#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
#define RT_HEAP_SIZE 1024
/* 从内部SRAM里面分配一部分静态内存来作为rtt的堆空间，这里配置为4KB */
static uint32_t rt_heap[RT_HEAP_SIZE];
RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

/* 该部分代码截取自函数rt_hw_board_init() */
#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
//rt_system_heap_init((void*)HEAP_BEGIN, (void*)SRAM_END);
rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif


/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/
#include "board.h"
#include "rtthread.h"


/*
*************************************************************************
*                               变量
*************************************************************************
*/
/* 定义线程控制块指针 */
static rt_thread_t led1_thread = RT_NULL;

/*
*************************************************************************
*                             函数声明
*************************************************************************
*/
static void led1_thread_entry(void* parameter);


/*
*************************************************************************
*                             main 函数
*************************************************************************
*/
/**
* @brief  主函数
* @param  无
* @retval 无
*/
int main(void)
{
    /*
    * 开发板硬件初始化，RTT系统初始化已经在main函数之前完成，
    * 即在component.c文件中的rtthread_startup()函数中完成了。
    * 所以在main函数中，只需要创建线程和启动线程即可。
    */
    led1_thread =                          /* 线程控制块指针 */
    rt_thread_create( "led1",              /* 线程名字 */
                    led1_thread_entry,   /* 线程入口函数 */
                    RT_NULL,             /* 线程入口函数参数 */
                    512,                 /* 线程栈大小 */
                    3,                   /* 线程的优先级 */
                    20);                 /* 线程时间片 */

    /* 启动线程，开启调度 */
    if (led1_thread != RT_NULL)
        rt_thread_startup(led1_thread);
    else
        return -1;
}

/*
*************************************************************************
*                             线程定义
*************************************************************************
*/

static void led1_thread_entry(void* parameter)
{
    while (1)
    {
        LED_G(OFF);
        rt_thread_delay(500);   /* 延时500个tick */
        //rt_kprintf("led1_thread running,LED1_OFF\r\n");

        LED_G(ON);
        rt_thread_delay(500);   /* 延时500个tick */
        //rt_kprintf("led1_thread running,LED1_ON\r\n");
    }
}

/*******************************END OF FILE****************************/