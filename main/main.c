/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

/*
 * This example program shows how to use Square Line in ESP32-S3-LCD-EV-Board .
 * Design the LVGL UI and implement relay control.
 */
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
#include "app/relay_control.h"
#include "main.h"


uint32_t relay_on_time = 0;
uint32_t relay_off_time = 0;

uint32_t get_relay_on_time()
{
    return relay_on_time;
}

uint32_t get_relay_off_time()
{
    return relay_off_time;
}

void set_relay_on_time(uint32_t time)
{
    relay_on_time = time;
}

void set_relay_off_time(uint32_t time)
{
    relay_off_time = time;
}


bool system_flag = SYSTEM_OFF;

bool get_system_flag()
{
    return system_flag;
}

void set_system_flag(bool sys_state)
{
    system_flag = sys_state;
}

void toggle_system_flag()
{
    system_flag = !system_flag;
}

bool relay_status = RELAY_STATUS_OFF;

bool get_relay_status()
{
    return relay_status;
}

void set_relay_status(bool state)
{
    relay_status = state;
}

void toggle_relay_status()
{
    relay_status = !relay_status;
}

TimerHandle_t relay_control_timer;
void change_timer_period(uint32_t time_ms)
{
    xTimerChangePeriod(relay_control_timer, (time_ms / portTICK_PERIOD_MS), portMAX_DELAY);
}

static void relay_control_timer_callback(TimerHandle_t timer)
{
    if (get_relay_on_time() > 0 && get_relay_off_time() > 0) {
        toggle_relay_status();
        if (get_relay_status() == RELAY_STATUS_ON) {
            change_timer_period(get_relay_on_time());
            relay_control(RELAY_ON);
            relay_on_time_light(LIGHT_ON);
            relay_off_time_light(LIGHT_OFF);
        } else {
            change_timer_period(get_relay_off_time());
            relay_control(RELAY_OFF);
            relay_on_time_light(LIGHT_OFF);
            relay_off_time_light(LIGHT_ON);
        }
    } else {
        ESP_LOGI (TAG, "Input error!!!");
    }
}

static void relay_control_timer_create()
{
    relay_control_timer = xTimerCreate((const char *)"relay_control_timer",
                                       (TickType_t)(1000 / portTICK_PERIOD_MS), pdTRUE, (void *)RELAY_CONTROL_TIMER_ID,
                                       (TimerCallbackFunction_t)relay_control_timer_callback);
}

void relay_control_timer_switch(bool timer_state)
{
    if (timer_state) {
        xTimerStart(relay_control_timer, portMAX_DELAY);
    } else {
        xTimerStop(relay_control_timer, portMAX_DELAY);
    }
}

void app_lvgl_display(void)
{
    bsp_display_lock(0);
    ui_init();
    widget_event_init(); // add widget event callback
    bsp_display_unlock();
}

void app_main(void)
{
    bsp_i2c_init(); // Initialize I2C (for touch)
    bsp_display_start(); // Initialize display and LVGL
    bsp_display_backlight_on(); // Turn on display backlight
    relay_control_init(); // Relay initialization
    app_lvgl_display(); // Add and show objects on display
    relay_control_timer_create(); // Create RTOS Timer

    ESP_LOGI(TAG, "Relay Control Demo.");

    while (1) {
        if (get_system_flag()) {
            // System is running
        } else {
            ESP_LOGI (TAG, "Please pressed button to open!!!");
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }
        ESP_LOGI (TAG, "Relay Controller Running!!!");
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}
