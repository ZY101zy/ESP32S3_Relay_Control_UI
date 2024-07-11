/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
/*
 * @Author: ZY101zy zhouyi@espressif.com
 * @Date: 2024-07-10 13:36:22
 * @LastEditors: ZY101zy zhouyi@espressif.com
 * @LastEditTime: 2024-07-11 10:40:08
 * @FilePath: /relay_control/main/main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "main.h"


uint32_t relay_on_time = 0;
uint32_t relay_off_time = 0;

uint8_t system_flag = SYSTEM_OFF;



/*******************************************************************************
* Private functions
*******************************************************************************/


void relay_control_init()
{
    //zero-initialize the config structure.
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.20
    io_conf.pin_bit_mask = 1ULL << RELAY_CTRL_PIN;
    //disable pull-down mode
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    //enable pull-up mode
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
    gpio_set_level(RELAY_CTRL_PIN, RELAY_OFF);

}

void relay_control(int value)
{
    gpio_set_level(RELAY_CTRL_PIN, value);
}



// *INDENT-OFF*
void app_lvgl_display(void)
{
    bsp_display_lock(0);

    ui_init();
    // add app function
    widget_event_init();

    bsp_display_unlock();
}

void app_main(void)
{
    /* Initialize I2C (for touch and audio) */
    bsp_i2c_init();

    /* Initialize display and LVGL */
    bsp_display_start();

    /* Turn on display backlight */
    bsp_display_backlight_on();

    /* Relay Initialization*/
    relay_control_init();

    /* Add and show objects on display */
    app_lvgl_display();

    ESP_LOGI(TAG, "Example initialization done.");

    while (1) {
        if (system_flag) {
            // ESP_LOGI (TAG, "SYSTEM ON!!! \r\n");
            if (relay_on_time > 0 && relay_off_time > 0) {
                relay_control(RELAY_ON);
                relay_on_time_light(STATUS_ON);
                relay_off_time_light(STATUS_OFF);
                vTaskDelay(relay_on_time / portTICK_PERIOD_MS);
                relay_control(RELAY_OFF);
                relay_on_time_light(STATUS_OFF);
                relay_off_time_light(STATUS_ON);
                vTaskDelay(relay_off_time / portTICK_PERIOD_MS);
            } else {
                ESP_LOGI (TAG, "Please input correct time!!! \r\n");
                vTaskDelay(50 / portTICK_PERIOD_MS);
            }

        } else {
            ESP_LOGI (TAG, "Please pressed button to open!!! \r\n");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            relay_on_time_light(STATUS_OFF);
            relay_off_time_light(STATUS_OFF);
        }
        // ESP_LOGI (TAG, "Relay Controller Running!!! \r\n");
    }

}
// *INDENT-ON*
