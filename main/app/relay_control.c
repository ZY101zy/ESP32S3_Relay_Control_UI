/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

/**
 * This procedure is suitable for GPIO operation of relay
 *
 */

#include "driver/gpio.h"
#include "bsp/esp32_s3_lcd_ev_board.h"
#include "main.h"
#include "app/relay_control.h"

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
