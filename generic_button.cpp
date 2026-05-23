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

GenericButton::GenericButton( std::string tag,
                              button_gpio_config_t *btn_gpio_cfg) {
	this->tag = tag;
    this->btn_gpio_cfg = btn_gpio_cfg;
    this->buttonType = std::string("GPIO");

        ESP_LOGI(this->tag.c_str(), "Button Type GPIO");
        // create gpio button
        const button_config_t btn_cfg = {0, 0};
        iot_button_new_gpio_device(&btn_cfg, btn_gpio_cfg, &this->btn);
        if(NULL == this->btn) {
            ESP_LOGE(this->tag.c_str(), "GPIO Button create failed");
        }
}

GenericButton::GenericButton( std::string tag,
                              button_adc_config_t *btn_adc_cfg) {
	this->tag = tag;
	this->btn_adc_cfg = btn_adc_cfg;
    this->buttonType = std::string("ADC");

    // .unit_id = ADC_UNIT_2,
    // .adc_channel = ADC_CHANNEL_5,
    // .button_index = 0,
    // .min = 100,
    // .max = 400,

        ESP_LOGI(this->tag.c_str(), "Button Type ADC");
        // create adc button
        const button_config_t btn_cfg = {0, 0};
        // ADC_ATTEN_DB_12 or ADC_ATTEN_DB11 is set in iot_button_new_adc_device
        iot_button_new_adc_device(&btn_cfg, btn_adc_cfg, &this->btn);
        if(NULL == this->btn) {
            ESP_LOGE(this->tag.c_str(), "ADC Button create failed");
        }
}

GenericButton::~GenericButton() {
	// TODO Auto-generated destructor stub
}

void GenericButton::RegisterCallbackForEvent(button_event_t event, button_cb_t cb) {
    ESP_LOGI(this->tag.c_str(), "RegisterCallbackForEvent called");
    iot_button_register_cb(this->btn, event, NULL, cb, NULL);
}

void GenericButton::RegisterCallbackForEvent(button_event_t event, button_cb_t cb, void *data) {
    ESP_LOGI(this->tag.c_str(), "RegisterCallbackForEvent called");
    iot_button_register_cb(this->btn, event, NULL, cb, data);
}

void GenericButton::RegisterCallbackForEvent(button_event_t event, button_event_args_t *args, button_cb_t cb) {
    ESP_LOGI(this->tag.c_str(), "RegisterCallbackForEvent called with args");
    iot_button_register_cb(this->btn, event, args, cb, NULL);
}

void GenericButton::RegisterCallbackForEvent(button_event_t event, button_event_args_t *args, button_cb_t cb, void *data) {
    ESP_LOGI(this->tag.c_str(), "RegisterCallbackForEvent called with args");
    iot_button_register_cb(this->btn, event, args, cb, data);
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
