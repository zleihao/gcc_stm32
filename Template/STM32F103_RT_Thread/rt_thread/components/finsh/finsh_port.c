/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rthw.h>
#include <rtconfig.h>
#include "bsp_debug_usart.h"

#ifndef RT_USING_FINSH
#error Please uncomment the line <#include "finsh_config.h"> in the rtconfig.h 
#endif

#ifdef RT_USING_FINSH

RT_WEAK char rt_hw_console_getchar(void)
{
     int ch = -1;

    if (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
    {
        ch = (int)USART_ReceiveData(USART1);
        USART_ClearFlag(USART1, USART_FLAG_RXNE);
    }
    else
    {
        if(USART_GetFlagStatus(USART1, USART_FLAG_ORE) != RESET)
        {
            USART_ClearFlag(USART1, USART_FLAG_ORE);
        }
        rt_thread_mdelay(10);
    }
    
    return ch;
}

#endif /* RT_USING_FINSH */

