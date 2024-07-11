/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#ifndef __LVGL_WIDGET_APP_H__
#define __LVGL_WIDGET_APP_H__

#include <stdlib.h>
#include "ui/ui.h"
#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Add event callback and initialization styles
 *
 */
void widget_event_init();

/**
 * @brief   Relay on indicator light style
 *
 * @param   on_time_status light on or not
 */
void relay_on_time_light(uint8_t on_time_status);

/**
 * @brief   Relay off indicator light style
 *
 * @param   off_time_status light on or not
 */
void relay_off_time_light(uint8_t off_time_status);



#ifdef __cplusplus
}
#endif

#endif /* __LVGL_WIDGET_APP_H__ */
