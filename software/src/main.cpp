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

#define LED_PIN     PC13

#define KEY0_PIN    PA3
#define KEY1_PIN    PA2
#define KEY2_PIN    PA1
#define KEY3_PIN    PA0
#define KEY4_PIN    PC15
#define KEY5_PIN    PC14
#define KEY6_PIN    PC13

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    pinMode(KEY0_PIN, INPUT_PULLUP);
    pinMode(KEY1_PIN, INPUT_PULLUP);
    pinMode(KEY2_PIN, INPUT_PULLUP);
    pinMode(KEY3_PIN, INPUT_PULLUP);
    pinMode(KEY4_PIN, INPUT_PULLUP);
    pinMode(KEY5_PIN, INPUT_PULLUP);
    pinMode(KEY6_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.printf("\n\n\n");
    Serial.printf("Blue Pill USB HID Keyboard started\n");
    Serial.printf("Compiled on " __DATE__ " " __TIME__ "\n");
    Keyboard.begin();
}

void loop()
{
    if (digitalRead(KEY0_PIN) == LOW)
    {
        Serial.printf("Key0 pressed\n");
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
    if (digitalRead(KEY1_PIN) == LOW)
    {
        Serial.printf("Key1 pressed\n");
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
    if (digitalRead(KEY2_PIN) == LOW)
    {
        Serial.printf("Key2 pressed\n");
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
    if (digitalRead(KEY3_PIN) == LOW)
    {
        Serial.printf("Key3 pressed\n");
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F4);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY3_PIN) == LOW);
    }
    if (digitalRead(KEY4_PIN) == LOW)
    {
        Serial.printf("Key4 pressed\n");
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F5);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY4_PIN) == LOW);
    }
    if (digitalRead(KEY5_PIN) == LOW)
    {
        Serial.printf("Key5 pressed\n");
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F6);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY5_PIN) == LOW);
    }
    if (digitalRead(KEY6_PIN) == LOW)
    {
        Serial.printf("Key6 pressed\n");
        Keyboard.press(KEY_LEFT_ALT);
        delay(100);
        Keyboard.press(KEY_LEFT_GUI);
        delay(100);
        Keyboard.press(KEY_F7);
        delay(100);
        Keyboard.releaseAll();
        /* Wait until releasing key */
        while (digitalRead(KEY6_PIN) == LOW);
    }
}
