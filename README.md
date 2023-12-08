# blue_pill_arduino_usb_hid_keyboard
Macro keyboard which uses Blue Pill (STM32F103) development board and Arduino framework.
Pressing a key sends Alt-Windows-F1 (or any combination you want) through USB to the host. The software is very simple: 
to change the key, you need to compile and re-program the device.
There is 3D printed case and 3D printed keycaps for the keyboard, but you can create your own case of course.

Schematic:
![Schematic](https://github.com/ivanovp/blue_pill_arduino_usb_hid_keyboard/blob/main/hardware/blue_pill_arduino_usb_hid_keyboard_bb.png?raw=true)

Photos:
![Macro keyboard top](https://github.com/ivanovp/blue_pill_arduino_usb_hid_keyboard/blob/main/blue_pill_arduino_usb_hid_keyboard_top.jpg?raw=true)
![Macro keyboard](https://github.com/ivanovp/blue_pill_arduino_usb_hid_keyboard/blob/main/blue_pill_arduino_usb_hid_keyboard.jpg?raw=true)

Bill of Materials:

Blue Pill (STM32F103C8, 64KiB flash):
https://www.hestore.hu/prod_10043289.html

Blue Pill (STM32F103C6, 32KiB flash):
https://pepita.hu/muszaki-cikk-elektronika-outlet-c6343/stm32f103c6t6-mikrokontroller-fejleszto-modul-p10464316

ST-Link V2:
https://www.hestore.hu/prod_10037590.html

Mechanical switches:
https://www.alza.hu/keychron-kailh-switch-set-35pcsset-brown-d6587566.htm
https://www.alza.hu/keychron-kailh-switch-set-35pcsset-red-d6587574.htm

