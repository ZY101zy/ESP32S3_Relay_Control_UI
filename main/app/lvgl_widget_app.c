/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include <stdio.h>
#include <stdbool.h>
#include "lvgl_widget_app.h"
#include "app/relay_control.h"

lv_obj_t *control_button_label;
static lv_style_t style_label;

static void controller_button(uint8_t sys_status)
{
    if (sys_status == SYSTEM_ON) {
        lv_obj_set_style_bg_color(ui_ScreenHome_Button_ButtonController, lv_color_hex(0x0000FF), LV_PART_MAIN);
        lv_label_set_text(control_button_label, "SYSTEM ON");
    } else {
        lv_obj_set_style_bg_color(ui_ScreenHome_Button_ButtonController, lv_color_hex(0xBEBEBE), LV_PART_MAIN);
        lv_label_set_text(control_button_label, "SYSTEM OFF");
    }
}

static void text_aera_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *ta = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED) {
        /**< Focus on the clicked text area */
        if (ui_ScreenHome_Keyboard_KeyboardInput != NULL) {
            lv_keyboard_set_textarea(ui_ScreenHome_Keyboard_KeyboardInput, ta);
        }
    } else if (code == LV_EVENT_READY) { /**< keyboard input over */
        const char *text_on = lv_textarea_get_text(ui_ScreenHome_Textarea_TextAreaOnTime);
        const char *text_off = lv_textarea_get_text(ui_ScreenHome_Textarea_TextAreaOffTime);
        // ESP_LOGI(TAG, "Relay on txt: %s", text_on);
        // ESP_LOGI(TAG, "Relay off txt: %s", text_off);

        char *endptr_on;
        char *endptr_off;

        uint32_t number_on = strtoul(text_on, &endptr_on, 10);
        uint32_t number_off = strtoul(text_off, &endptr_off, 10);
        // ESP_LOGI(TAG, "Relay on time set: %d ms", number_on);
        // ESP_LOGI(TAG, "Relay off time set: %d ms", number_off);
        // ESP_LOGI(TAG, "Relay on endptr_on: %c", *endptr_on);
        // ESP_LOGI(TAG, "Relay off endptr_off: %c", *endptr_off);

        if (endptr_on == text_on) { // text_aera is empty
            // relay_on_time = 0;
            set_relay_on_time(0);
            // ESP_LOGI(TAG, "Relay on time set: %d ms", relay_on_time);
            ESP_LOGI(TAG, "Relay on time set: %d ms", get_relay_on_time());
        } else if (*endptr_on != '\0') {
            ESP_LOGE(TAG, "Relay on input format is error!!!");
            // relay_on_time = 0;
            set_relay_on_time(0);
        } else {
            // relay_on_time = number_on;
            set_relay_on_time(number_on);
            ESP_LOGI(TAG, "Relay on time set: %d ms", get_relay_on_time());
        }

        if (endptr_off == text_off) { // text_aera is empty
            // relay_off_time = 0;
            set_relay_off_time(0);
            ESP_LOGI(TAG, "Relay off time set: %d ms", get_relay_off_time());
        } else if (*endptr_off != '\0') {
            ESP_LOGE(TAG, "Relay off input format is error!!!");
            // relay_off_time = 0;
            set_relay_off_time(0);
        } else {
            // relay_off_time = number_off;
            set_relay_off_time(number_off);
            ESP_LOGI(TAG, "Relay off time set: %d ms", get_relay_off_time());
        }
    }
}

static void control_button_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        toggle_system_flag();
        if (get_system_flag()) {
            if (get_relay_on_time() > 0 && get_relay_off_time() > 0) {
                change_timer_period(get_relay_on_time());
                controller_button(SYSTEM_ON);
                relay_control(RELAY_ON);
                relay_on_time_light(LIGHT_ON);
                relay_off_time_light(LIGHT_OFF);
                set_relay_status(RELAY_STATUS_ON);
                relay_control_timer_switch(TIMER_STATUS_ON);
            } else {
                ESP_LOGI (TAG, "Please input correct time!!!");
                set_system_flag(SYSTEM_OFF);
            }
        } else {
            controller_button(SYSTEM_OFF);
            relay_control_timer_switch(TIMER_STATUS_OFF);
            relay_control(RELAY_OFF);
            relay_on_time_light(LIGHT_OFF);
            relay_off_time_light(LIGHT_OFF);
        }
    }
}

void relay_on_time_light(uint8_t on_time_status)
{
    if (on_time_status) {
        lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOnTimeLed, lv_color_hex(0x008000), LV_PART_MAIN);
    } else {
        lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOnTimeLed, lv_color_hex(0xBEBEBE), LV_PART_MAIN);
    }
}

void relay_off_time_light(uint8_t off_time_status)
{
    if (off_time_status) {
        lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOffTimeLed, lv_color_hex(0xFF0000), LV_PART_MAIN);
    } else {
        lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOffTimeLed, lv_color_hex(0xBEBEBE), LV_PART_MAIN);
    }
}

void widget_event_init()
{
    /**< Focus it on one of the text areas to start */
    lv_keyboard_set_textarea(ui_ScreenHome_Keyboard_KeyboardInput, ui_ScreenHome_Textarea_TextAreaOnTime);
    lv_obj_add_event_cb(ui_ScreenHome_Textarea_TextAreaOnTime, text_aera_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenHome_Textarea_TextAreaOffTime, text_aera_event_cb, LV_EVENT_ALL, NULL);

    /**< Button set */
    lv_obj_set_style_bg_color(ui_ScreenHome_Button_ButtonController, lv_color_hex(0xBEBEBE), LV_PART_MAIN);
    lv_obj_add_event_cb(ui_ScreenHome_Button_ButtonController, control_button_event_cb, LV_EVENT_ALL, NULL);

    /**< Button label set */
    control_button_label = lv_label_create(ui_ScreenHome_Button_ButtonController);
    lv_style_init(&style_label);
    lv_style_set_text_color(&style_label, lv_color_hex(0x000000));
    lv_style_set_text_font(&style_label, &lv_font_montserrat_20);
    lv_obj_add_style(control_button_label, &style_label, 0);
    lv_label_set_text(control_button_label, "SYSTEM OFF");
    lv_obj_center(control_button_label);

    /**< indicator light */
    lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOnTimeLed, lv_color_hex(0xBEBEBE), LV_PART_MAIN);
    lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOffTimeLed, lv_color_hex(0xBEBEBE), LV_PART_MAIN);
}
