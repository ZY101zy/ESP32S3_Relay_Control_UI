/*
 * @Author: ZY101zy zhouyi@espressif.com
 * @Date: 2024-07-10 10:15:09
 * @LastEditors: ZY101zy zhouyi@espressif.com
 * @LastEditTime: 2024-07-11 15:26:25
 * @FilePath: /relay_control/main/main.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __MAIN__H
#define __MAIN__H


#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "bsp/esp32_s3_lcd_ev_board.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "app/lvgl_widget_app.h"

#define TAG "RELAY_CONTROL"
#define RELAY_CTRL_PIN GPIO_NUM_20
#define RELAY_ON 0
#define RELAY_OFF 1

#define SYSTEM_ON 1
#define SYSTEM_OFF 0

#define STATUS_ON 1
#define STATUS_OFF 0

// typedef uint8_t status_t;
extern uint32_t relay_on_time;
extern uint32_t relay_off_time;
extern uint8_t system_flag;


extern uint8_t system_flag;
/**
 * @brief relay control Timer
 */
extern TimerHandle_t relay_control_timer;
#define RELAY_STATUS_ON true
#define RELAY_STATUS_OFF false
#define RELAY_CONTROL_TIMER_ID 1

#define TIMER_STATUS_ON true
#define TIMER_STATUS_OFF false

extern bool relay_status;
extern void relay_control_timer_switch(bool timer_state);


void relay_control_init();

void relay_control(int value);








#endif
