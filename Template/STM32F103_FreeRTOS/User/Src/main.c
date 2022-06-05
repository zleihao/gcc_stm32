/**		 
 * @Date:               2022.3.16 
 * @Revision:           V1.0
 * @author:             点灯大师
 * @Affiliated unit：   黄河科技学院
 * @Description:        基于STM32F103的FreeRtos工程
 * @Email:              im_leihao@163.com
 * @github:             https://github.com/zleihao
 */

#include "Free.h"
#include "bsp_debug_usart.h"

/**	
 * @brief:  BSP_Init
 * @param:  无
 * @return: 无
 * @note:   初始化用到的外设
 */
static void BSP_Init(void) {
	/* STM32 中断优先级分组为 4，即 4bit 都用来表示抢占优先级，范围为： 0~15
	* 优先级分组只需要分组一次即可，以后如果有其他的任务需要用到中断，
	* 都统一用这个优先级分组，千万不要再分组，切忌。
	*/
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	 
	
	//初始化 USART1
	USARTx_Config();
}


int main(void) {
	
	BSP_Init();
	printf("FreeRtos 模板\n");
  
	while (1)
	{
	
	}

}
