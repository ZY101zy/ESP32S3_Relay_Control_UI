/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
/*
 * @Author: ZY101zy zhouyi@espressif.com
 * @Date: 2024-07-10 16:00:30
 * @LastEditors: ZY101zy zhouyi@espressif.com
 * @LastEditTime: 2024-07-11 10:26:07
 * @FilePath: /relay_control/main/app/lvgl_widget_app.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#ifndef __LVGL_WIDGET__APP__H__
#define __LVGL_WIDGET__APP__H__

#include <stdlib.h>
#include "ui/ui.h"
#include "main.h"

/**
 * widget event callback
 */
void widget_event_init();
void relay_on_time_light(uint8_t on_time_status);
void relay_off_time_light(uint8_t off_time_status);



#endif
