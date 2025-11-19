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
#include <cstdint>
#include <string>

class GenericButton {
public:
	GenericButton(std::string tag, gpio_num_t buttonPin, uint8_t activeLevel, bool disablePull, std::string buttonType);
	virtual ~GenericButton();
    void RegisterCallbackForEvent(button_event_t event, button_cb_t cb);
    void RegisterCallbackForEvent(button_event_t event, button_event_args_t *args, button_cb_t cb);
    void Stop();
    void Resume();

private:	
	gpio_num_t buttonPin; // the pin number for this button
	uint8_t activeLevel; // 0 = active when pressed_down, 1 = active when pressed_up
	bool disablePull; // disable PU/PD function for gpio
	std::string buttonType; // the button type {"GPIO"|"ADC"|"MATRIX"}

    std::string tag = "GenericButton";

    button_handle_t btn;
    };

#endif /* GENERIC_BUTTON_HPP_ */
