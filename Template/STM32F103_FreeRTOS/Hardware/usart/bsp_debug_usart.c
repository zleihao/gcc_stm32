#include "bsp_debug_usart.h"

//配置 USART 
void USARTx_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//打开时钟
	DEBUG_USARTx_GPIO_CLK_FUN(DEBUG_UASRTx_GPIO_CLK,ENABLE);
	
	//TX
	GPIO_InitStruct.GPIO_Pin = DEBUG_USARTx_TX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(DEBUG_USARTx_TX_GPIO_PORT,&GPIO_InitStruct);
	
	//RX
	GPIO_InitStruct.GPIO_Pin = DEBUG_USARTx_RX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(DEBUG_USARTx_RX_GPIO_PORT,&GPIO_InitStruct);
	
	
	USART_InitTypeDef USART_InitStruct;
		
	DEBUG_USARTx_CLK_FUN(DEBUG_USARTx_CLK,ENABLE);
	
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_Init(DEBUG_USARTx,&USART_InitStruct);
	
	USART_Cmd(DEBUG_USARTx,ENABLE);
}

///重定向c库函数printf到串口，重定向后可使用printf函数
int _write (int fd, char *pBuffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        while((USART1->SR&0X40)==0);//等待上一次串口数据发送完成
        USART1->DR = (uint8_t) pBuffer[i];       //写DR,串口1将发送数据
    }
    return size;
}
