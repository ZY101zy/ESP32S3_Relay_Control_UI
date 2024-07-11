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
#include "main.h"


uint32_t relay_on_time = 0;
uint32_t relay_off_time = 0;

bool system_flag = SYSTEM_OFF;

TimerHandle_t relay_control_timer;
bool relay_status = RELAY_STATUS_OFF;

static void relay_control_timer_callback(TimerHandle_t timer)
{
    if (relay_on_time > 0 && relay_off_time > 0) {
        relay_status = !relay_status;
        if (relay_status == RELAY_STATUS_ON) {
            xTimerChangePeriod(relay_control_timer, (relay_on_time / portTICK_PERIOD_MS), portMAX_DELAY);
            relay_control(RELAY_ON);
            relay_on_time_light(LIGHT_ON);
            relay_off_time_light(LIGHT_OFF);
        } else {
            xTimerChangePeriod(relay_control_timer, (relay_off_time / portTICK_PERIOD_MS), portMAX_DELAY);
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

void relay_control_init()
{
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE; // disable interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = 1ULL << RELAY_CTRL_PIN;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
    gpio_set_level(RELAY_CTRL_PIN, RELAY_OFF);
}

void relay_control(int value)
{
    gpio_set_level(RELAY_CTRL_PIN, value);
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
        if (system_flag) {
            // System is running
        } else {
            ESP_LOGI (TAG, "Please pressed button to open!!!");
            vTaskDelay(200 / portTICK_PERIOD_MS);
        }
        ESP_LOGI (TAG, "Relay Controller Running!!!");
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }

}
