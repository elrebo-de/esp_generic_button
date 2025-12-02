/*
 * Example program to use a button with elrebo-de/generic_button
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
    ESP_LOGI("onBoardButton Callback", "for Event BUTTON_SINGLE_CLICK called!");

    iot_button_print_event((button_handle_t)arg);
    //esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();
    //if (cause != ESP_SLEEP_WAKEUP_UNDEFINED) {
    //    ESP_LOGI(TAG, "Wake up from light sleep, reason %d", cause);
    //}

    // bei jedem BUTTON_SINGLE_CLICK wird einmalig die Folge rot, grün, blau angezeigt
    led->setLedState(1);

	for(int i=0; i<3;i++) {
        if (i % 3 == 0) led->setLedPixelColor(0, 16, 0, 0); // pixel 0, color red, intensity 16/256
        if (i % 3 == 1) led->setLedPixelColor(0, 0, 16, 0); // pixel 0, color green, intensity 16/256
        if (i % 3 == 2) led->setLedPixelColor(0, 0, 0, 16); // pixel 0, color blue, intensity 16/256
        led->blink();
        led->blink();
    }
}

// Callback function for BUTTON_DOUBLE_CLICK event from onBoardButton
extern "C" void callback_onBoardButton_BUTTON_DOUBLE_CLICK(void *arg, void *data)
{
    ESP_LOGI("Button Callback", "for Event BUTTON_DOUBLE_CLICK called!");

    iot_button_print_event((button_handle_t)arg);
    //esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();
    //if (cause != ESP_SLEEP_WAKEUP_UNDEFINED) {
    //    ESP_LOGI(TAG, "Wake up from light sleep, reason %d", cause);
    //}

    // bei jedem BUTTON_DOUBLE_CLICK wird einmalig die Folge rot, rot, grün, grün, blau, blau angezeigt
    led->setLedState(1);

	for(int i=0; i<3;i++) {
        if (i % 3 == 0) led->setLedPixelColor(0, 16, 0, 0); // pixel 0, color red, intensity 16/256
        if (i % 3 == 1) led->setLedPixelColor(0, 0, 16, 0); // pixel 0, color green, intensity 16/256
        if (i % 3 == 2) led->setLedPixelColor(0, 0, 0, 16); // pixel 0, color blue, intensity 16/256
        led->blink();
        led->blink();
        led->blink();
        led->blink();
    }
}

// Callback function for BUTTON_LONG_PRESS_START (5000 ms) event from onBoardButton
extern "C" void callback_onBoardButton_BUTTON_LONG_PRESS_START_5000(void *arg, void *data)
{
    ESP_LOGI("Button Callback", "for Event BUTTON_LONG_PRESS_START_5000 called!");

    iot_button_print_event((button_handle_t)arg);

    // bei jedem BUTTON_LONG_PRESS_START (5000 ms) wird dreieinmal weiß geblinkt
    led->setLedState(1);
    led->setLedPixelColor(0, 16, 16, 16); // pixel 0, color white, intensity 16/256

	for(int i=0; i<3;i++) {
        led->blink();
    }
}

extern "C" void app_main(void)
{
    ESP_LOGI(tag, "onBoardButton Example Program");

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

	        /* ESP32-C3 w/ LCD display */
		    std::string("ESP32-C3 w/ LCD display onBoardLed"),
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

    GenericButton onBoardButton(
	   std::string("onBoardButton"),
	   #if defined(CONFIG_IDF_TARGET_ESP32C6)
 	       /* ESP32-C6-DevKitM-1 V1.0 */
		   (gpio_num_t) 9, // GPIO
		   0, // active = DOWN
		   false, // pull enabled
		   std::string("GPIO")
	   #elif defined(CONFIG_IDF_TARGET_ESP32C3)
	       /* Waveshare ESP32-C3-Zero */
		   (gpio_num_t) 9, // GPIO
		   0, // active = DOWN
		   false, // pull enabled
		   std::string("GPIO")
	   #elif defined(CONFIG_IDF_TARGET_ESP32)
	       /* M5 Atom Lite */
		   (gpio_num_t) 39, // GPIO
		   0, // active = DOWN
		   true, // pull disabled - M5 Atom does not support internal PU/PD on this gpio
		   std::string("GPIO")
	   #endif
	   );

    onBoardButton.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK);
    onBoardButton.RegisterCallbackForEvent(BUTTON_DOUBLE_CLICK, callback_onBoardButton_BUTTON_DOUBLE_CLICK);

    button_event_args_t args = {
       { // long_press
           5000, // press_time
       }
    };
    onBoardButton.RegisterCallbackForEvent(BUTTON_LONG_PRESS_START, &args, callback_onBoardButton_BUTTON_LONG_PRESS_START_5000);

    ESP_LOGI(tag, "wait for button callback events");
    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delay 1 second
    }
}
