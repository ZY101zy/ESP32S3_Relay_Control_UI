// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: relay_control

#ifndef _RELAY_CONTROL_UI_H
#define _RELAY_CONTROL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"

// SCREEN: ui_ScreenHome
void ui_ScreenHome_screen_init(void);
extern lv_obj_t * ui_ScreenHome;
extern lv_obj_t * ui_ScreenHome_Container_ContainerSysName;
extern lv_obj_t * ui_ScreenHome_Label_LabelSysName;
extern lv_obj_t * ui_ScreenHome_Container_ContainerTimeSetting;
extern lv_obj_t * ui_ScreenHome_Container_ContainerONTime;
extern lv_obj_t * ui_ScreenHome_Panel_PanelOnTimeLed;
extern lv_obj_t * ui_ScreenHome_Label_LabelOnTime;
extern lv_obj_t * ui_ScreenHome_Textarea_TextAreaOnTime;
extern lv_obj_t * ui_ScreenHome_Container_ContainerOffTime;
extern lv_obj_t * ui_ScreenHome_Panel_PanelOffTimeLed;
extern lv_obj_t * ui_ScreenHome_Label_LabelOffTime;
extern lv_obj_t * ui_ScreenHome_Textarea_TextAreaOffTime;
extern lv_obj_t * ui_ScreenHome_Container_ContainerController;
extern lv_obj_t * ui_ScreenHome_Keyboard_KeyboardInput;
extern lv_obj_t * ui_ScreenHome_Button_ButtonController;
extern lv_obj_t * ui_Startevents____initial_actions0;





void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
