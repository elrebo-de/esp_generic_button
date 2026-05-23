## ADC Buttons Example

This example demonstrates how to utilize the `generic_button` component to read button events from ADC buttons.

## Hardware

* Any GPIO button, which can be used for ADC, on any development board can be used in this example.

## Build and Flash

Build the project and flash it to the board, then run the monitor tool to view the serial output:

* Run `. <directory with ESP-IDF version>/export.sh` to set IDF environment
* Run `idf.py set-target esp32xx` to set target chip
* Run `idf.py -p PORT flash monitor` to build, flash and monitor the project

(To exit the serial monitor, type `Ctrl-]` (or on a Mac `Ctrl-Option-6`).

See the Getting Started Guide for all the steps to configure and use the ESP-IDF to build projects.

## Function
In this example an ADC channel connected to a resistor ladder with six switches is used. It is connected to GPIO pin 0 of a ESP32C3 Supermini board. On the ESP32C3 SoC GPIO pin 0 is connected to ADC unit 1 and ADC channel 0. 

With the selected resistor values and asupply voltage of 3.3 V the voltages for the six ADC buttons are:
* button_index 0: 0.01 V (min: 0 mV, max: 154 mV)
* button_index 1: 0.30 V (min: 155 mV, max: 477 mV)
* button_index 2: 0.65 V (min: 478 mV, max: 852 mV)
* button_index 3: 1.05 V (min: 853 mV, max: 1323 mV)
* button_index 4: 1.60 V (min: 1324 mV, max: 1964 mV)
* button_index 5: 2.33 V (min: 1965 mV, max: 2612 mV)

An ADC unit and an ADC channel is selected in the constructor of the ADC button. This ADC channel is connected to a GPIO pin. 

In addition a button index and a voltage range (min and max) are specified for each ADC button.

Six ADC buttons are constructed.

Now every time when a voltage in this range is detected, the button events for this button are triggered.

A callback function is defined for the event BUTTON_SINGLE_CLICK.

This callback function is registered with all six buttons. The button index is supplied to the callback function in the data attribute.

In case of a single_click the onboard LED is flashed n times according to the button index.

## Example Output

```
I (300) main_task: Calling app_main()
I (300) onBoard Button: onBoardButton Example Program
I (300) M5 Atom Lite onBoardLed: configured to use addressable LED strip!
I (300) onBoardButton: Button Type GPIO
I (310) button: IoT Button Version: 4.1.6
I (310) onBoardButton: RegisterCallbackForEvent called
I (310) onBoardButton: RegisterCallbackForEvent called
I (320) onBoardButton: RegisterCallbackForEvent called with args
I (320) onBoardButton: RegisterCallbackForEvent called with args
I (330) onBoard Button: wait for button callback events
I (7620) onBoardButton Callback: for Event BUTTON_SINGLE_CLICK called!
I (7620) button: BUTTON_SINGLE_CLICK
I (7620) M5 Atom Lite onBoardLed: Turning the LED ON!
I (8130) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (8630) M5 Atom Lite onBoardLed: Turning the LED ON!
I (9130) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (9630) M5 Atom Lite onBoardLed: Turning the LED ON!
I (10130) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (12710) Button Callback: for Event BUTTON_DOUBLE_CLICK called!
I (12710) button: BUTTON_DOUBLE_CLICK
I (12710) M5 Atom Lite onBoardLed: Turning the LED ON!
I (13210) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (13710) M5 Atom Lite onBoardLed: Turning the LED ON!
I (14210) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (14710) M5 Atom Lite onBoardLed: Turning the LED ON!
I (15210) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (15710) M5 Atom Lite onBoardLed: Turning the LED ON!
I (16210) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (16710) M5 Atom Lite onBoardLed: Turning the LED ON!
I (17210) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (17710) M5 Atom Lite onBoardLed: Turning the LED ON!
I (18210) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (20300) Button Callback: for Event BUTTON_MULTIPLE_CLICK called!
I (20300) button: BUTTON_MULTIPLE_CLICK
I (20300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (20800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (21300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (21800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (22300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (22800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (23300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (23800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (24300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (24800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (25300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (25800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (26300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (26800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (27300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (27800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (28300) M5 Atom Lite onBoardLed: Turning the LED ON!
I (28800) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (35100) Button Callback: for Event BUTTON_LONG_PRESS_START_5000 called!
I (35100) button: BUTTON_LONG_PRESS_START
I (35100) M5 Atom Lite onBoardLed: Turning the LED ON!
I (35600) M5 Atom Lite onBoardLed: Turning the LED OFF!
I (36100) M5 Atom Lite onBoardLed: Turning the LED ON!
I (36600) M5 Atom Lite onBoardLed: Turning the LED OFF!
```