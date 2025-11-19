/*
 * generic_button.cpp
 *
 *  Created on: 30.10.2025
 *      Author: christophoberle
 */

#include "generic_button.hpp"
#include "esp_log.h"
//#include "driver/gpio.h"
//#include "soc/clk_tree_defs.h"

GenericButton::GenericButton(std::string tag, gpio_num_t buttonPin, uint8_t activeLevel, bool disablePull,
                             std::string buttonType) {
	this->tag = tag;
    this->buttonPin = buttonPin;
    this->activeLevel = activeLevel;
    this->disablePull = disablePull;
    this->buttonType = buttonType;

    // configure button according to buttonType
    // buttonType {"GPIO"|"ADC"|"MATRIX"}
  	if (this->buttonType == "GPIO") {
        ESP_LOGI(this->tag.c_str(), "Button Type GPIO");
        // create gpio button
        const button_config_t btn_cfg = {0, 0};
        const button_gpio_config_t btn_gpio_cfg = {
            .gpio_num = this->buttonPin,
            .active_level = this->activeLevel,
            .enable_power_save = false,
            .disable_pull = this->disablePull,
        };
        button_handle_t gpio_btn = NULL;
        esp_err_t ret = iot_button_new_gpio_device(&btn_cfg, &btn_gpio_cfg, &gpio_btn);
        if(NULL == gpio_btn) {
            ESP_LOGE(this->tag.c_str(), "Button create failed");
        }

        this->btn = gpio_btn;
    }
    else if (this->buttonType == "ADC") {
        ESP_LOGI(this->tag.c_str(), "button_adc: not yet implemented!");
    }
    else if (this->buttonType == "MATRIX") {
        ESP_LOGI(this->tag.c_str(), "button_matrix: not yet implemented!");
    }
}

GenericButton::~GenericButton() {
	// TODO Auto-generated destructor stub
}

void GenericButton::RegisterCallbackForEvent(button_event_t event, button_cb_t cb) {
    ESP_LOGI(this->tag.c_str(), "RegisterCallbackForEvent called");

    esp_err_t ret = iot_button_register_cb(this->btn, event, NULL, cb, NULL);

    //ESP_ERROR_CHECK(ret);
}

void GenericButton::RegisterCallbackForEvent(button_event_t event, button_event_args_t *args, button_cb_t cb) {
    ESP_LOGI(this->tag.c_str(), "RegisterCallbackForEvent called with args");

    esp_err_t ret = iot_button_register_cb(this->btn, event, args, cb, NULL);

    //ESP_ERROR_CHECK(ret);
}

void GenericButton::Stop() {
    ESP_LOGI(this->tag.c_str(), "iot_button_stop called");

    esp_err_t ret = iot_button_stop();

    ESP_ERROR_CHECK(ret);
}

void GenericButton::Resume() {
    ESP_LOGI(this->tag.c_str(), "iot_button_resume called");

    esp_err_t ret = iot_button_resume();

    ESP_ERROR_CHECK(ret);
}
