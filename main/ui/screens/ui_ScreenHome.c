// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: relay_control

#include "../ui.h"

void ui_ScreenHome_screen_init(void)
{
    ui_ScreenHome = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenHome, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenHome, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(ui_ScreenHome, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenHome, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Container_ContainerSysName = lv_obj_create(ui_ScreenHome);
    lv_obj_remove_style_all(ui_ScreenHome_Container_ContainerSysName);
    lv_obj_set_width(ui_ScreenHome_Container_ContainerSysName, 407);
    lv_obj_set_height(ui_ScreenHome_Container_ContainerSysName, 47);
    lv_obj_set_x(ui_ScreenHome_Container_ContainerSysName, 7);
    lv_obj_set_y(ui_ScreenHome_Container_ContainerSysName, -203);
    lv_obj_set_align(ui_ScreenHome_Container_ContainerSysName, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScreenHome_Container_ContainerSysName, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_ScreenHome_Container_ContainerSysName, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScreenHome_Container_ContainerSysName,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScreenHome_Label_LabelSysName = lv_label_create(ui_ScreenHome_Container_ContainerSysName);
    lv_obj_set_width(ui_ScreenHome_Label_LabelSysName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenHome_Label_LabelSysName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenHome_Label_LabelSysName, -216);
    lv_obj_set_y(ui_ScreenHome_Label_LabelSysName, -207);
    lv_obj_set_align(ui_ScreenHome_Label_LabelSysName, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenHome_Label_LabelSysName, "Relay Control Panel");
    lv_obj_set_style_text_font(ui_ScreenHome_Label_LabelSysName, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Container_ContainerTimeSetting = lv_obj_create(ui_ScreenHome);
    lv_obj_remove_style_all(ui_ScreenHome_Container_ContainerTimeSetting);
    lv_obj_set_width(ui_ScreenHome_Container_ContainerTimeSetting, 748);
    lv_obj_set_height(ui_ScreenHome_Container_ContainerTimeSetting, 50);
    lv_obj_set_x(ui_ScreenHome_Container_ContainerTimeSetting, -3);
    lv_obj_set_y(ui_ScreenHome_Container_ContainerTimeSetting, -140);
    lv_obj_set_align(ui_ScreenHome_Container_ContainerTimeSetting, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScreenHome_Container_ContainerTimeSetting, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_ScreenHome_Container_ContainerTimeSetting, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScreenHome_Container_ContainerTimeSetting,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_ScreenHome_Container_ContainerTimeSetting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenHome_Container_ContainerTimeSetting, 40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Container_ContainerONTime = lv_obj_create(ui_ScreenHome_Container_ContainerTimeSetting);
    lv_obj_remove_style_all(ui_ScreenHome_Container_ContainerONTime);
    lv_obj_set_width(ui_ScreenHome_Container_ContainerONTime, 365);
    lv_obj_set_height(ui_ScreenHome_Container_ContainerONTime, 85);
    lv_obj_set_x(ui_ScreenHome_Container_ContainerONTime, -116);
    lv_obj_set_y(ui_ScreenHome_Container_ContainerONTime, -94);
    lv_obj_set_align(ui_ScreenHome_Container_ContainerONTime, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScreenHome_Container_ContainerONTime, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_ScreenHome_Container_ContainerONTime, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScreenHome_Container_ContainerONTime,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_ScreenHome_Container_ContainerONTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenHome_Container_ContainerONTime, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Panel_PanelOnTimeLed = lv_obj_create(ui_ScreenHome_Container_ContainerONTime);
    lv_obj_set_width(ui_ScreenHome_Panel_PanelOnTimeLed, 25);
    lv_obj_set_height(ui_ScreenHome_Panel_PanelOnTimeLed, 25);
    lv_obj_set_x(ui_ScreenHome_Panel_PanelOnTimeLed, -410);
    lv_obj_set_y(ui_ScreenHome_Panel_PanelOnTimeLed, -207);
    lv_obj_set_align(ui_ScreenHome_Panel_PanelOnTimeLed, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScreenHome_Panel_PanelOnTimeLed, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_ScreenHome_Panel_PanelOnTimeLed, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START,
                          LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_clear_flag(ui_ScreenHome_Panel_PanelOnTimeLed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOnTimeLed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHome_Panel_PanelOnTimeLed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ScreenHome_Panel_PanelOnTimeLed, lv_color_hex(0xFFFFFF),
                                   LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Label_LabelOnTime = lv_label_create(ui_ScreenHome_Container_ContainerONTime);
    lv_obj_set_width(ui_ScreenHome_Label_LabelOnTime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenHome_Label_LabelOnTime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenHome_Label_LabelOnTime, -252);
    lv_obj_set_y(ui_ScreenHome_Label_LabelOnTime, -178);
    lv_obj_set_align(ui_ScreenHome_Label_LabelOnTime, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenHome_Label_LabelOnTime, "ON Time (ms)");
    lv_obj_set_style_text_font(ui_ScreenHome_Label_LabelOnTime, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Textarea_TextAreaOnTime = lv_textarea_create(ui_ScreenHome_Container_ContainerONTime);
    lv_obj_set_width(ui_ScreenHome_Textarea_TextAreaOnTime, 155);
    lv_obj_set_height(ui_ScreenHome_Textarea_TextAreaOnTime, 45);
    lv_obj_set_x(ui_ScreenHome_Textarea_TextAreaOnTime, -141);
    lv_obj_set_y(ui_ScreenHome_Textarea_TextAreaOnTime, -139);
    lv_obj_set_align(ui_ScreenHome_Textarea_TextAreaOnTime, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_ScreenHome_Textarea_TextAreaOnTime, "Placeholder...");
    lv_obj_clear_flag(ui_ScreenHome_Textarea_TextAreaOnTime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_ScreenHome_Textarea_TextAreaOnTime, &lv_font_montserrat_20,
                               LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_ScreenHome_Container_ContainerOffTime = lv_obj_create(ui_ScreenHome_Container_ContainerTimeSetting);
    lv_obj_remove_style_all(ui_ScreenHome_Container_ContainerOffTime);
    lv_obj_set_width(ui_ScreenHome_Container_ContainerOffTime, 365);
    lv_obj_set_height(ui_ScreenHome_Container_ContainerOffTime, 85);
    lv_obj_set_x(ui_ScreenHome_Container_ContainerOffTime, 179);
    lv_obj_set_y(ui_ScreenHome_Container_ContainerOffTime, -140);
    lv_obj_set_align(ui_ScreenHome_Container_ContainerOffTime, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScreenHome_Container_ContainerOffTime, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_ScreenHome_Container_ContainerOffTime, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScreenHome_Container_ContainerOffTime,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_ScreenHome_Container_ContainerOffTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenHome_Container_ContainerOffTime, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Panel_PanelOffTimeLed = lv_obj_create(ui_ScreenHome_Container_ContainerOffTime);
    lv_obj_set_width(ui_ScreenHome_Panel_PanelOffTimeLed, 25);
    lv_obj_set_height(ui_ScreenHome_Panel_PanelOffTimeLed, 25);
    lv_obj_set_x(ui_ScreenHome_Panel_PanelOffTimeLed, 46);
    lv_obj_set_y(ui_ScreenHome_Panel_PanelOffTimeLed, -132);
    lv_obj_set_align(ui_ScreenHome_Panel_PanelOffTimeLed, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScreenHome_Panel_PanelOffTimeLed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHome_Panel_PanelOffTimeLed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHome_Panel_PanelOffTimeLed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ScreenHome_Panel_PanelOffTimeLed, lv_color_hex(0xFFFFFF),
                                   LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Label_LabelOffTime = lv_label_create(ui_ScreenHome_Container_ContainerOffTime);
    lv_obj_set_width(ui_ScreenHome_Label_LabelOffTime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenHome_Label_LabelOffTime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenHome_Label_LabelOffTime, 134);
    lv_obj_set_y(ui_ScreenHome_Label_LabelOffTime, -134);
    lv_obj_set_align(ui_ScreenHome_Label_LabelOffTime, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenHome_Label_LabelOffTime, "OFF Time (ms)");
    lv_obj_set_style_text_font(ui_ScreenHome_Label_LabelOffTime, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Textarea_TextAreaOffTime = lv_textarea_create(ui_ScreenHome_Container_ContainerOffTime);
    lv_obj_set_width(ui_ScreenHome_Textarea_TextAreaOffTime, 155);
    lv_obj_set_height(ui_ScreenHome_Textarea_TextAreaOffTime, 45);
    lv_obj_set_x(ui_ScreenHome_Textarea_TextAreaOffTime, 275);
    lv_obj_set_y(ui_ScreenHome_Textarea_TextAreaOffTime, -130);
    lv_obj_set_align(ui_ScreenHome_Textarea_TextAreaOffTime, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_ScreenHome_Textarea_TextAreaOffTime, "Placeholder...");
    lv_obj_clear_flag(ui_ScreenHome_Textarea_TextAreaOffTime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_font(ui_ScreenHome_Textarea_TextAreaOffTime, &lv_font_montserrat_20,
                               LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_ScreenHome_Container_ContainerController = lv_obj_create(ui_ScreenHome);
    lv_obj_remove_style_all(ui_ScreenHome_Container_ContainerController);
    lv_obj_set_width(ui_ScreenHome_Container_ContainerController, 761);
    lv_obj_set_height(ui_ScreenHome_Container_ContainerController, 354);
    lv_obj_set_x(ui_ScreenHome_Container_ContainerController, 4);
    lv_obj_set_y(ui_ScreenHome_Container_ContainerController, 65);
    lv_obj_set_align(ui_ScreenHome_Container_ContainerController, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScreenHome_Container_ContainerController, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenHome_Container_ContainerController, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ScreenHome_Container_ContainerController,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_ScreenHome_Container_ContainerController, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenHome_Container_ContainerController, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenHome_Keyboard_KeyboardInput = lv_keyboard_create(ui_ScreenHome_Container_ContainerController);
    lv_keyboard_set_mode(ui_ScreenHome_Keyboard_KeyboardInput, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_ScreenHome_Keyboard_KeyboardInput, 750);
    lv_obj_set_height(ui_ScreenHome_Keyboard_KeyboardInput, 269);
    lv_obj_set_x(ui_ScreenHome_Keyboard_KeyboardInput, -426);
    lv_obj_set_y(ui_ScreenHome_Keyboard_KeyboardInput, 59);
    lv_obj_set_align(ui_ScreenHome_Keyboard_KeyboardInput, LV_ALIGN_CENTER);

    lv_obj_set_style_text_font(ui_ScreenHome_Keyboard_KeyboardInput, &lv_font_montserrat_20,
                               LV_PART_ITEMS | LV_STATE_DEFAULT);

    ui_ScreenHome_Button_ButtonController = lv_btn_create(ui_ScreenHome_Container_ContainerController);
    lv_obj_set_width(ui_ScreenHome_Button_ButtonController, 724);
    lv_obj_set_height(ui_ScreenHome_Button_ButtonController, 67);
    lv_obj_set_x(ui_ScreenHome_Button_ButtonController, -219);
    lv_obj_set_y(ui_ScreenHome_Button_ButtonController, 209);
    lv_obj_set_align(ui_ScreenHome_Button_ButtonController, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScreenHome_Button_ButtonController, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenHome_Button_ButtonController, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenHome_Button_ButtonController, lv_color_hex(0x808080),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenHome_Button_ButtonController, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_ScreenHome_Button_ButtonController, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_ScreenHome_Button_ButtonController, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ScreenHome_Button_ButtonController, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_ScreenHome_Button_ButtonController, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenHome_Button_ButtonController, &lv_font_montserrat_14,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_keyboard_set_textarea(ui_ScreenHome_Keyboard_KeyboardInput, ui_ScreenHome_Textarea_TextAreaOnTime);

}
