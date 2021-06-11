/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-01-25     vikrantthakur       the first version
 */
#ifndef APPLICATIONS_MAIN_H_
#define APPLICATIONS_MAIN_H_

/// PIN HANDLING ///
#define LED0_PIN               GET_PIN(B, 14)  // RED LED
#define LED1_PIN               GET_PIN(B, 7)   // BLUE LED
#define PIR_PIN                GET_PIN(G, 9)   // PIR PIN
#define RELAY_PIN              GET_PIN(G, 14)   // RELAY PIN

// THREAD HANDLING ///
#define THREAD_STACK_SIZE      1024
#define THREAD_TIMESLICE       500


#define THREAD_PRIORITY        1

// Handling data over uart


#endif /* APPLICATIONS_MAIN_H_ */
