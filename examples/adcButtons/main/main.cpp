/*
 * Example program to use an ADC button with elrebo-de/generic_button
 */

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "generic_button.hpp"
#include "onboard_led.hpp"
#include "esp_log.h"

#include <iot_button.h>

static const char *tag = "onBoard Button";

// pointer to onBoardLed
OnBoardLed *led;


// Callback function for BUTTON_SINGLE_CLICK event from onBoardButton
extern "C" void callback_onBoardButton_BUTTON_SINGLE_CLICK(void *arg, void *data)
{
    button_adc_config_t *btn_adc_cfg = (button_adc_config_t *)data;
    uint8_t buttonIndex = btn_adc_cfg->button_index;

    ESP_LOGI("adcButtons Callback", "for Event BUTTON_SINGLE_CLICK called from button_index %u", buttonIndex);

    // at each BUTTON_SINGLE_CLICK the onBoard LED blinks <n> times according to the buttonIndex
    led->setLedState(1);
    led->setLedPixelColor(0, 16, 16, 16); // pixel 0, color white, intensity 16/256

	for(int i=0; i<= buttonIndex; i++) {
        led->blink();
        led->blink();
    }
}

extern "C" void app_main(void)
{
    ESP_LOGI(tag, "adcButtons Example Program");

    /* Configure the onboard led */
    OnBoardLed onBoardLed(
	    #if defined(CONFIG_IDF_TARGET_ESP32C6)
 	        /* ESP32-C6-DevKitM-1 V1.0 */
	        std::string("ESP32-C6-DevKitM-1 V1.0 onBoardLed"),
		    (gpio_num_t) 8,
		    std::string("GRB"),
		    std::string("RMT"),
		    LED_MODEL_WS2812,
	    #elif defined(CONFIG_IDF_TARGET_ESP32C3)
	        /* Waveshare ESP32-C3-Zero
		    std::string("Waveshare ESP32-C3-Zero onBoardLed"),
		    (gpio_num_t) 10,
		    std::string("RGB"),
		    std::string("RMT"),
		    LED_MODEL_WS2812, */

	        /* ESP32-C3 */
		    std::string("ESP32-C3 onBoardLed"),
		    (gpio_num_t) 8,
            (uint8_t) 0, // activeLevel
	    #elif defined(CONFIG_IDF_TARGET_ESP32)
	        /* M5 Atom Lite */
		    std::string("M5 Atom Lite onBoardLed"),
		    (gpio_num_t) 27,
		    std::string("GRB"),
		    std::string("RMT"),
		    LED_MODEL_WS2812,
	    #endif
		500.0);

    led = &onBoardLed;
    led->setLedState(0);
    led->show();

    // set ADC button configuration
    adc_oneshot_unit_handle_t *adc_handle = NULL; // will be set in first ADC button constructor

    // adcButton0
    button_adc_config_t btn_adc_cfg_0 = {
        .adc_handle = adc_handle,           /**< handle of adc unit, if NULL will create new one internal, else will use the handle */
        .unit_id = ADC_UNIT_1,               /**< ADC unit */
        .adc_channel = ADC1_GPIO0_CHANNEL,   /**< Channel of ADC */
        .button_index = 0,                   /**< button index on the channel */
        .min = 0,                            /**< min voltage in mv corresponding to the button */
        .max = 154,                          /**< max voltage in mv corresponding to the button */
    };

    // adcButton1
    button_adc_config_t btn_adc_cfg_1 = {
        .adc_handle = adc_handle,           /**< handle of adc unit, if NULL will create new one internal, else will use the handle */
        .unit_id = ADC_UNIT_1,               /**< ADC unit */
        .adc_channel = ADC1_GPIO0_CHANNEL,   /**< Channel of ADC */
        .button_index = 1,                   /**< button index on the channel */
        .min = 155,                          /**< min voltage in mv corresponding to the button */
        .max = 477,                          /**< max voltage in mv corresponding to the button */
    };

    // adcButton2
    button_adc_config_t btn_adc_cfg_2 = {
        .adc_handle = adc_handle,           /**< handle of adc unit, if NULL will create new one internal, else will use the handle */
        .unit_id = ADC_UNIT_1,               /**< ADC unit */
        .adc_channel = ADC1_GPIO0_CHANNEL,   /**< Channel of ADC */
        .button_index = 2,                   /**< button index on the channel */
        .min = 478,                          /**< min voltage in mv corresponding to the button */
        .max = 852,                         /**< max voltage in mv corresponding to the button */
    };

    // adcButton3
    button_adc_config_t btn_adc_cfg_3 = {
        .adc_handle = adc_handle,           /**< handle of adc unit, if NULL will create new one internal, else will use the handle */
        .unit_id = ADC_UNIT_1,               /**< ADC unit */
        .adc_channel = ADC1_GPIO0_CHANNEL,   /**< Channel of ADC */
        .button_index = 3,                   /**< button index on the channel */
        .min = 853,                         /**< min voltage in mv corresponding to the button */
        .max = 1323,                         /**< max voltage in mv corresponding to the button */
    };

    // adcButton4
    button_adc_config_t btn_adc_cfg_4 = {
        .adc_handle = adc_handle,           /**< handle of adc unit, if NULL will create new one internal, else will use the handle */
        .unit_id = ADC_UNIT_1,               /**< ADC unit */
        .adc_channel = ADC1_GPIO0_CHANNEL,   /**< Channel of ADC */
        .button_index = 4,                   /**< button index on the channel */
        .min = 1324,                         /**< min voltage in mv corresponding to the button */
        .max = 1964,                         /**< max voltage in mv corresponding to the button */
    };

    // adcButton5
    button_adc_config_t btn_adc_cfg_5 = {
        .adc_handle = adc_handle,           /**< handle of adc unit, if NULL will create new one internal, else will use the handle */
        .unit_id = ADC_UNIT_1,               /**< ADC unit */
        .adc_channel = ADC1_GPIO0_CHANNEL,   /**< Channel of ADC */
        .button_index = 5,                   /**< button index on the channel */
        .min = 1965,                         /**< min voltage in mv corresponding to the button */
        .max = 2612,                         /**< max voltage in mv corresponding to the button */
    };

    GenericButton adcButton0(std::string("adcButton0"), &btn_adc_cfg_0);
    adcButton0.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK, (void *)&btn_adc_cfg_0);

    GenericButton adcButton1(std::string("adcButton1"), &btn_adc_cfg_1);
    adcButton1.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK, (void *)&btn_adc_cfg_1);

    GenericButton adcButton2(std::string("adcButton2"), &btn_adc_cfg_2);
    adcButton2.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK, (void *)&btn_adc_cfg_2);

    GenericButton adcButton3(std::string("adcButton3"), &btn_adc_cfg_3);
    adcButton3.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK, (void *)&btn_adc_cfg_3);

    GenericButton adcButton4(std::string("adcButton4"), &btn_adc_cfg_4);
    adcButton4.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK, (void *)&btn_adc_cfg_4);

    GenericButton adcButton5(std::string("adcButton5"), &btn_adc_cfg_5);
    adcButton5.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK, (void *)&btn_adc_cfg_5);

    ESP_LOGI(tag, "wait for button callback events");
    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delay 1 second
    }
}
