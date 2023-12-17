/**
 * @file        main.cpp
 * @brief       Entry point and main program
 * @author      Copyright (C) Peter Ivanov, 2023
 *
 * Created      2023-11-30 11:30:53
 * Last modify: 2023-12-06 19:03:55 ivanovp {Time-stamp}
 * Licence:     GPL
 */

#include <Arduino.h>
#include <Keyboard.h>

#define ENABLE_SERIAL   0

#define LED_PIN     PC13

#define KEY_NUMBER  14

#define KEY0_PIN    PA4
#define KEY1_PIN    PA3
#define KEY2_PIN    PA2
#define KEY3_PIN    PA1
#define KEY4_PIN    PA0
#define KEY5_PIN    PC15
#define KEY6_PIN    PC14
#define KEY7_PIN    PB3
#define KEY8_PIN    PB4
#define KEY9_PIN    PB5
#define KEY10_PIN   PB6
#define KEY11_PIN   PB7
#define KEY12_PIN   PB8
#define KEY13_PIN   PB9

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    pinMode(KEY0_PIN, INPUT_PULLUP);
#if KEY_NUMBER > 1
    pinMode(KEY1_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 2
    pinMode(KEY2_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 3
    pinMode(KEY3_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 4
    pinMode(KEY4_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 5
    pinMode(KEY5_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 6
    pinMode(KEY6_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 7
    pinMode(KEY7_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 8
    pinMode(KEY8_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 9
    pinMode(KEY9_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 10
    pinMode(KEY10_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 11
    pinMode(KEY11_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 12
    pinMode(KEY12_PIN, INPUT_PULLUP);
#endif
#if KEY_NUMBER > 13
    pinMode(KEY13_PIN, INPUT_PULLUP);
#endif
#if ENABLE_SERIAL
    Serial.begin(115200);
    Serial.printf("\n\n\n");
    Serial.printf("Blue Pill USB HID Keyboard started\n");
    Serial.printf("Compiled on " __DATE__ " " __TIME__ "\n");
#endif
    Keyboard.begin();
}

void loop()
{
    if (digitalRead(KEY0_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key0 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F1);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY0_PIN) == LOW);
    }
#if KEY_NUMBER > 1
    if (digitalRead(KEY1_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key1 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F2);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY1_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 2
    if (digitalRead(KEY2_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key2 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F3);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY2_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 3
    if (digitalRead(KEY3_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key3 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F5);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY3_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 4
    if (digitalRead(KEY4_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key4 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F6);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY4_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 5
    if (digitalRead(KEY5_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key5 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F7);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY5_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 6
    if (digitalRead(KEY6_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key6 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F8);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY6_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 7
    if (digitalRead(KEY7_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key7 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('0');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY7_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 8
    if (digitalRead(KEY8_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key8 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('1');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY8_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 9
    if (digitalRead(KEY9_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key9 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('2');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY9_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 10
    if (digitalRead(KEY10_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key10 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('3');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY10_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 11
    if (digitalRead(KEY11_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key11 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('4');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY11_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 12
    if (digitalRead(KEY12_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key12 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('5');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY12_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 13
    if (digitalRead(KEY13_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.printf("Key13 pressed\n");
#endif
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press('6');
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY13_PIN) == LOW);
    }
#endif
}
