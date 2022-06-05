#ifndef _BSP_USART_H
#define _BSP_USART_H

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stdio.h"


#define DEBUG_USARTx  					USART1
#define DEBUG_USARTx_CLK_FUN			RCC_APB2PeriphClockCmd
#define DEBUG_USARTx_CLK				RCC_APB2Periph_USART1


#define DEBUG_USARTx_GPIO_CLK_FUN	 	RCC_APB2PeriphClockCmd
#define DEBUG_UASRTx_GPIO_CLK     		RCC_APB2Periph_GPIOA

//GPIO -> TX
#define DEBUG_USARTx_TX_GPIO_PORT   	GPIOA
#define DEBUG_USARTx_TX_GPIO_PIN		GPIO_Pin_9

//GPIO -> RX
#define DEBUG_USARTx_RX_GPIO_PORT   	GPIOA
#define DEBUG_USARTx_RX_GPIO_PIN    	GPIO_Pin_10

void USARTx_Config(void);

#endif /* _BSP_USART_H */

