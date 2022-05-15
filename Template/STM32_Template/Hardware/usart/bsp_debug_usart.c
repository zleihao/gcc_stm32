#include "bsp_debug_usart.h"

/**
 * @brief  usart_init
 * @param  flck 时钟频率
 * 		   usart1频率为72M，其余串口为36M
 * @return 无
 * @note   初始化usart
 */
void usart_init(uint8_t flck) {
	float temp;
	uint16_t mantissa;  //波特率整数
	uint16_t fraction;  //波特率小数

	temp = (float)(flck*1000000)/(115200*16);  //得到 USARTDIV
	mantissa = temp;                           //得到整数部分
	fraction = (temp - mantissa)*16;           //得到小数部分
	mantissa <<= 4;
	mantissa += fraction;                      //写入到BRR的最终值

	//打开串口时钟
	RCC->APB2ENR |= (1 << 14);
	//打开GPIOA时钟
	RCC->APB2ENR |= (1 << 2);
	
	//配置TX、RX引脚
	GPIOA->CRH &= 0xFFFFF00F;  //清空 PIN10 PIN9
	// TX：复用推挽输出 RX：输入模式
	GPIOA->CRH |= 0x000008B0;  

	//复位串口
	RCC->APB2RSTR |= (1 << 14);
	//停止复位
	RCC->APB2RSTR &= ~(1 << 14);
	//usart工作模式
	USART1->BRR = mantissa; //波特率
	USART1->CR1 |= 0x200C;  //使能usart1、无校验位
	USART1->CR2 &= ~(3 << 12); //1个停止位
}

//重定向c库函数printf到串口，重定向后可使用printf函数
int _write (int fd, char *pBuffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        while((USART1->SR&0X40)==0);//等待上一次串口数据发送完成
        USART1->DR = (uint8_t) pBuffer[i];       //写DR,串口1将发送数据
    }
    return size;
}
