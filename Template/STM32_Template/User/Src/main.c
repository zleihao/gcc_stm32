/**		 
 * @Date:               2022.3.16 
 * @Revision:           V1.0
 * @Writer:             点灯大师
 * @Affiliated unit：   黄河科技学院
 * @Description:        基于STM32F103的固件库工程模板
 * @Email:              im_leihao@163.com
 * @gitee:              https://gitee.com/zleihao/STM32F103.git
 */
#include "bsp_debug_usart.h"

int main(void) {
	//初始化USART1
	usart_init(72);

    printf("Hello world\n");

	while (1)
	{

	}

}
