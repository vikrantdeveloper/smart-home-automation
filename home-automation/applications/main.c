/*@created by : Vikrant Thakur
 * @email id:vikrantthakur97@gmail.com
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-01-19     RT-Thread    first version
 */

#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <stdio.h>
#include <rtdbg.h>

#include "main.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG

// Creating Structures for Threads
struct rt_thread thread1;
struct rt_thread thread2;
struct rt_thread thread3;

static char thread1_stack[THREAD_STACK_SIZE];
static char thread2_stack[THREAD_STACK_SIZE];
static char thread3_stack[THREAD_STACK_SIZE];

static rt_uint8_t led_notification = 0;
static rt_uint8_t relay_handle = 0;

static void initialise()
{
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(RELAY_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(PIR_PIN, PIN_MODE_INPUT);
}

static void uart_handling()
{
    // need to write & implement
}

static void thread1_entry(void* parameter)
{
    // toggles the LED as per the PIR values
    while (1)
        {
            if(led_notification == 1){
                rt_pin_write(LED1_PIN, PIN_HIGH);
                rt_thread_mdelay(1000);

                rt_pin_write(LED1_PIN, PIN_LOW);
                rt_thread_mdelay(1000);
            }
            else if(led_notification == 0){
                rt_pin_write(LED0_PIN, PIN_HIGH);
                rt_thread_mdelay(1000);

                rt_pin_write(LED0_PIN, PIN_LOW);
                rt_thread_mdelay(1000);
            }
        }
}

static void thread2_entry(void* parameter)
{
    while(1)
    {
        // handles the PIR values
        if(rt_pin_read(PIR_PIN) == 1)
        {
            led_notification = 1;
            relay_handle = 1;
        }
        else{
            led_notification = 0;
        }
        rt_thread_mdelay(100);
    }
}
static void thread3_entry(void* parameter)
{
        if(relay_handle == 1){
            rt_pin_write(RELAY_PIN, PIN_HIGH);
            rt_thread_mdelay(500);
            relay_handle = 0;
        }
        if(relay_handle == 0){
            rt_pin_write(RELAY_PIN, PIN_LOW);
        }
}

// Setting thread Priority

#ifdef RT_USING_TC
static void _tc_cleanup()
{
    /* lock scheduler */
    rt_enter_critical();

    if (thread1.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread1);
    if (thread2.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread2);
    if (thread3.stat != RT_THREAD_CLOSE)
        rt_thread_detach(&thread3);

    /* unlock scheduler */
    rt_exit_critical();
}
int _tc_thread_priority()
{
    /* set tc cleanup */
    tc_cleanup(_tc_cleanup);


    return RT_TICK_PER_SECOND;
}
FINSH_FUNCTION_EXPORT(_tc_thread_priority, a priority thread test);
#endif




int main(void)
{

    // Initialise the pin configuration
    initialise();

    // LED notification thread
    rt_thread_init(&thread1,"t1",thread1_entry, RT_NULL, &thread1_stack[0], sizeof(thread1_stack),THREAD_PRIORITY + 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread1);

    // PIR sensor Thread
    rt_thread_init(&thread2,"t2",thread2_entry, RT_NULL,&thread2_stack[0], sizeof(thread2_stack),THREAD_PRIORITY - 1, THREAD_TIMESLICE);

    rt_thread_startup(&thread2);

    // Relay handling Thread
    rt_thread_init(&thread3,"t2",thread3_entry, RT_NULL,&thread3_stack[0], sizeof(thread3_stack),THREAD_PRIORITY, THREAD_TIMESLICE);

    rt_thread_startup(&thread3);

    return 0;
}
