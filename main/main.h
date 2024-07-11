/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "esp_log.h"

#ifdef __cplusplus
extern "C" {
#endif

/**< ESP log tag */
#define TAG "RELAY_CONTROL"

/**
 * @brief Relay and used GPIO definition
 *
 */
#define RELAY_CTRL_PIN GPIO_NUM_20
#define RELAY_ON 0
#define RELAY_OFF 1

/**
 * @brief System running state definition
 */
#define SYSTEM_ON true
#define SYSTEM_OFF false
extern bool system_flag;

/**
 * @brief relay control Timer
 */
extern TimerHandle_t relay_control_timer;
extern uint32_t relay_on_time;
extern uint32_t relay_off_time;
#define LIGHT_ON true
#define LIGHT_OFF false
#define RELAY_STATUS_ON true
#define RELAY_STATUS_OFF false
#define RELAY_CONTROL_TIMER_ID 1u
#define TIMER_STATUS_ON true
#define TIMER_STATUS_OFF false

extern bool relay_status;
/**
 * @brief   Switch on/off relay control Timer
 *
 * @param timer_state   Timer start or stop
 */
void relay_control_timer_switch(bool timer_state);

/**
 * @brief   Relay control GPIO initialization
 */
void relay_control_init();

/**
 * @brief   Relay control GPIO high and low level
 */
void relay_control(int value);



#ifdef __cplusplus
}
#endif


#endif /* __MAIN_H__ */
