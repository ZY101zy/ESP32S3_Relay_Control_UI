/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __MAIN__H
#define __MAIN__H


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "bsp/esp32_s3_lcd_ev_board.h"
#include "lvgl.h"
#include "ui/ui.h"

#define TAG "RELAY_CONTROL"
#define RELAY_CTRL_PIN GPIO_NUM_20
#define RELAY_ON 0
#define RELAY_OFF 1

void relay_control_init();

void relay_control(int value);








#endif
