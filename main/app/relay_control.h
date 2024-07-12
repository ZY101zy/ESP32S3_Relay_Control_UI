/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __RELAY_CONTROL_H__
#define __RELAY_CONTROL_H__


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Relay and used GPIO definition
 *
 */
#define RELAY_CTRL_PIN GPIO_NUM_20
#define RELAY_ON 0
#define RELAY_OFF 1

/**
 * @brief   Relay control GPIO initialization
 */
void relay_control_init();

/**
 * @brief   Relay control GPIO high and low level
 */
void relay_control(int value);

#ifdef __cplusplus
}
#endif

#endif  /* __RELAY_CONTROL_H__ */
