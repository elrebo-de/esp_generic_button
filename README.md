# Generic Button component

This repository contains an ESP-IDF component for a generic button. It runs on
any ESP32 processor and is built using the ESP-IDF build system in version 6.0+.

The component is implemented as C++ class `GenericButton`.

## Connecting the component

The constructor of class `GenericButton` has five parameters:

| Parameter   | Type of Parameter | Usage                                        |
|:------------|:------------------|:---------------------------------------------|
| tag         | std::string       | the tag to be used in the ESP log            |
| buttonPin   | gpio_num_t        | the gpio number of the button                |
| activeLevel | uint8_t           | active level of button                       |
| disablePull | bool              | disable PU/PD function for buttonPin         |
| buttonType  | std::string       | the button type: "GPIO" or "ADC" or "MATRIX" |

# Usage

## API
The API of the component is located in the include directory ```include/generic_button.hpp``` and defines the
C++ class ```GenericButton```

Currently only buttonType == "GPIO" is implemented!

```C++
class GenericButton {
public:
	GenericButton(std::string tag, gpio_num_t buttonPin, uint8_t activeLevel, bool disablePull, std::string buttonType);
	virtual ~GenericButton();
    void RegisterCallbackForEvent(button_event_t event, button_cb_t cb);
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
```

For every button event you want to detect, you have to
* prepare a callback function to handle the event
* register the event and the callback function for the button

``` C++
// Callback function for BUTTON_SINGLE_CLICK event from onBoardButton
extern "C" void callback_onBoardButton_BUTTON_SINGLE_CLICK(void *arg, void *data)
{
    ESP_LOGI("onBoardButton Callback", "for Event BUTTON_SINGLE_CLICK called!");

    iot_button_print_event((button_handle_t)arg);

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
```

To register this callback function for the BUTTON_SINGLE_CLICK event you have to call
```
onBoardButton.RegisterCallbackForEvent(BUTTON_SINGLE_CLICK, callback_onBoardButton_BUTTON_SINGLE_CLICK);
```

Now, every time a BUTTON_SINGLE_CLICK is detected for the onBoardButton, the callback function is called 
and the sequence red -> green -> blue is displayed on the led. See examples/onBoardButton for details.

# License

This component is provided under the Apache 2.0 license.
