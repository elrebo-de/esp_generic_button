## Generic Button Example

This example demonstrates how to utilize the `generic_button` component to read button events.

## Hardware

* Any GPIO on any development board can be used in this example.

## Build and Flash

Build the project and flash it to the board, then run the monitor tool to view the serial output:

* Run `. <directory with ESP-IDF version>/export.sh` to set IDF environment
* Run `idf.py set-target esp32xx` to set target chip
* Run `idf.py -p PORT flash monitor` to build, flash and monitor the project

(To exit the serial monitor, type `Ctrl-]` (or on a Mac `Ctrl-Option-6`).

See the Getting Started Guide for all the steps to configure and use the ESP-IDF to build projects.

## Function
A button is defined.
Two callback functions are defined for the events
* BUTTON_SINGLE_CLICK and
* BUTTON_DOUBLE_CLICK.

In case of a single_click the onboard LED is flashed three times (if LED type is "LED strip": red, green ,blue),
in case of a double click the onboard LED is flashed six times (if LED type is "LED strip": red, red, green, green, blue, blue).

## Example Output

```
I (272) main_task: Calling app_main()
I (272) onBoard Button: onBoardButton Example Program
I (272) ESP32-C6-DevKitM-1 V1.0 onBoardLed: configured to use addressable LED strip!
I (282) onBoardButton: Button Type GPIO
I (282) button: IoT Button Version: 4.1.3
I (282) onBoardButton: RegisterCallbackForEvent called
I (292) onBoardButton: RegisterCallbackForEvent called
I (292) onBoard Button: program waiting for button callback events
I (6482) onBoardButton Callback: for Event BUTTON_SINGLE_CLICK called!
I (6482) button: BUTTON_SINGLE_CLICK
I (6482) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (6992) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (7492) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (7992) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (8492) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (8992) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (12082) Button Callback: for Event BUTTON_DOUBLE_CLICK called!
I (12082) button: BUTTON_DOUBLE_CLICK
I (12082) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (12592) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (13092) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (13592) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (14092) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (14592) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (15092) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (15592) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (16092) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (16592) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (17092) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (17592) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (20132) Button Callback: for Event BUTTON_DOUBLE_CLICK called!
I (20132) button: BUTTON_DOUBLE_CLICK
I (20132) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (20642) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (21142) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (21642) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (22142) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (22642) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (23142) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (23642) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (24142) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (24642) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (25142) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (25642) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (26712) onBoardButton Callback: for Event BUTTON_SINGLE_CLICK called!
I (26712) button: BUTTON_SINGLE_CLICK
I (26712) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (27222) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (27722) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (28222) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (28722) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED ON!
I (29222) ESP32-C6-DevKitM-1 V1.0 onBoardLed: Turning the LED OFF!
I (30302) main_task: Returned from app_main()
```