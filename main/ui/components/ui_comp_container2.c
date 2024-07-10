// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: relay_control

#include "../ui.h"


// COMPONENT Container2

lv_obj_t * ui_Container_Container2_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Container_Container2;
    cui_Container_Container2 = lv_obj_create(comp_parent);
    lv_obj_remove_style_all(cui_Container_Container2);
    lv_obj_set_width(cui_Container_Container2, 193);
    lv_obj_set_height(cui_Container_Container2, 50);
    lv_obj_set_x(cui_Container_Container2, -279);
    lv_obj_set_y(cui_Container_Container2, -195);
    lv_obj_set_align(cui_Container_Container2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Container_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_CONTAINER_CONTAINER2_NUM);
    children[UI_COMP_CONTAINER_CONTAINER2_CONTAINER_CONTAINER2] = cui_Container_Container2;
    lv_obj_add_event_cb(cui_Container_Container2, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Container_Container2, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Container_Container2_create_hook(cui_Container_Container2);
    return cui_Container_Container2;
}
