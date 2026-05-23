/*
 * generic_button.hpp
 *
 *  Created on: 30.10.2025
 *      Author: christophoberle
 */

#ifndef GENERIC_BUTTON_HPP_
#define GENERIC_BUTTON_HPP_

#include <stdio.h>

#include "button_gpio.h"
#include "button_adc.h"
#include "button_matrix.h"
#include "button_types.h"
#include "iot_button.h"
#include "soc/adc_channel.h"
#include <cstdint>
#include <string>

class GenericButton {
public:
	GenericButton(std::string tag, button_gpio_config_t *btn_gpio_cfg);
	GenericButton(std::string tag, button_adc_config_t *btn_adc_cfg);
	virtual ~GenericButton();
    void RegisterCallbackForEvent(button_event_t event, button_cb_t cb);
    void RegisterCallbackForEvent(button_event_t event, button_cb_t cb, void *data);
    void RegisterCallbackForEvent(button_event_t event, button_event_args_t *args, button_cb_t cb);
    void RegisterCallbackForEvent(button_event_t event, button_event_args_t *args, button_cb_t cb, void *data);
    void Stop();
    void Resume();

private:	
	button_gpio_config_t *btn_gpio_cfg; // the button configuration for GPIO buttons
	button_adc_config_t *btn_adc_cfg; // the button configuration for ADC buttons
	std::string buttonType; // the button type {"GPIO"|"ADC"|"MATRIX"}

    std::string tag = "GenericButton";

    button_handle_t btn = NULL;
    };

#endif /* GENERIC_BUTTON_HPP_ */
