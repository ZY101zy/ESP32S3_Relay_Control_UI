/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */


#include "main.h"

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
        relay_control(RELAY_OFF);

        ESP_LOGI (TAG, "RELAY OFF!!!\r\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        relay_control(RELAY_ON);
        ESP_LOGI(TAG, "RELAY ON!!!\r\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

}
// *INDENT-ON*
