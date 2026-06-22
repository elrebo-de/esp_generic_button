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
I (254) main_task: Calling app_main()
I (254) onBoard Button: adcButtons Example Program
I (264) ESP32-C3 onBoardLed: configured to use GPIO LED!
================IO DUMP Start================
IO[8] -
  Pullup: 0, Pulldown: 1, DriveCap: 2
  InputEn: 0, OutputEn: [periph_sig_ctrl], OpenDrain: 0
  FuncSel: 1 (GPIO)
  GPIO Matrix SigOut ID: 128 (simple GPIO output)
  SleepSelEn: 1

=================IO DUMP End=================
I (294) adcButton0: Button Type ADC
I (294) adc_button: calibration scheme version is Curve Fitting
I (304) adc_button: Calibration Success
I (304) button: IoT Button Version: 4.1.6
I (304) adcButton0: RegisterCallbackForEvent called
I (314) adcButton1: Button Type ADC
I (314) adcButton1: RegisterCallbackForEvent called
I (314) adcButton2: Button Type ADC
I (324) adcButton2: RegisterCallbackForEvent called
I (324) adcButton3: Button Type ADC
I (334) adcButton3: RegisterCallbackForEvent called
I (334) adcButton4: Button Type ADC
I (334) adcButton4: RegisterCallbackForEvent called
I (344) adcButton5: Button Type ADC
I (344) adcButton5: RegisterCallbackForEvent called
I (354) onBoard Button: wait for button callback events
I (7964) adcButtons Callback: for Event BUTTON_SINGLE_CLICK called from button_index 4
I (7964) ESP32-C3 onBoardLed: Turning the LED ON!
I (8464) ESP32-C3 onBoardLed: Turning the LED OFF!
I (8964) ESP32-C3 onBoardLed: Turning the LED ON!
I (9464) ESP32-C3 onBoardLed: Turning the LED OFF!
I (9964) ESP32-C3 onBoardLed: Turning the LED ON!
I (10464) ESP32-C3 onBoardLed: Turning the LED OFF!
I (10964) ESP32-C3 onBoardLed: Turning the LED ON!
I (11464) ESP32-C3 onBoardLed: Turning the LED OFF!
I (11964) ESP32-C3 onBoardLed: Turning the LED ON!
I (12464) ESP32-C3 onBoardLed: Turning the LED OFF!
I (18464) adcButtons Callback: for Event BUTTON_SINGLE_CLICK called from button_index 0
I (18464) ESP32-C3 onBoardLed: Turning the LED ON!
I (18964) ESP32-C3 onBoardLed: Turning the LED OFF!
I (25364) adcButtons Callback: for Event BUTTON_SINGLE_CLICK called from button_index 2
I (25364) ESP32-C3 onBoardLed: Turning the LED ON!
I (25864) ESP32-C3 onBoardLed: Turning the LED OFF!
I (26364) ESP32-C3 onBoardLed: Turning the LED ON!
I (26864) ESP32-C3 onBoardLed: Turning the LED OFF!
I (27364) ESP32-C3 onBoardLed: Turning the LED ON!
I (27864) ESP32-C3 onBoardLed: Turning the LED OFF!

```