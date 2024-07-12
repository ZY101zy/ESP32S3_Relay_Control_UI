/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdbool.h>
#include "esp_log.h"

#ifdef __cplusplus
extern "C" {
#endif

/**< ESP log tag */
#define TAG "RELAY_CONTROL"

/**
 * @brief System running state definition
 */
#define SYSTEM_ON true
#define SYSTEM_OFF false
bool get_system_flag();
void set_system_flag(bool sys_state);
void toggle_system_flag();

/**
 * @brief relay control Timer
 */
void change_timer_period(uint32_t time_ms);
uint32_t get_relay_on_time();
uint32_t get_relay_off_time();
void set_relay_on_time(uint32_t time);
void set_relay_off_time(uint32_t time);

/**
 * @brief relay status
 */
bool get_relay_status();
void set_relay_status(bool state);
void toggle_relay_status();

#define LIGHT_ON true
#define LIGHT_OFF false
#define RELAY_STATUS_ON true
#define RELAY_STATUS_OFF false
#define RELAY_CONTROL_TIMER_ID 1u
#define TIMER_STATUS_ON true
#define TIMER_STATUS_OFF false

/**
 * @brief   Switch on/off relay control Timer
 *
 * @param timer_state   Timer start or stop
 */
void relay_control_timer_switch(bool timer_state);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */
