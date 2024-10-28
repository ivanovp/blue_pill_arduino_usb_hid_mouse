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
#include <Mouse.h>
#include <U8g2lib.h>
#include <Wire.h>

#define ENABLE_SERIAL   0
#define ENABLE_LCD      0

#define LED_PIN     PC13

#define SOFTWARE_DEBOUNCE_TIME_MS   500

#define KEY_NUMBER  7

#define KEY0_PIN    PA3
#define KEY1_PIN    PA2
#define KEY2_PIN    PA1
#define KEY3_PIN    PA0
#define KEY4_PIN    PC15
#define KEY5_PIN    PC14
#define KEY6_PIN    PC13
#define KEY7_PIN    PB4
#define KEY8_PIN    PB5
#define KEY9_PIN    PB6
#define KEY10_PIN   PB7
#define KEY11_PIN   PB8
#define KEY12_PIN   PB9
#define KEY13_PIN

uint32_t mouse_press_end_ms = 0;
// uint32_t mouse_press_time_ms = 10 * 1000;
uint32_t mouse_press_time_ms = 60 * 1000;
#if ENABLE_LCD
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g(U8G2_R0);
#endif

void setLed(bool on=true)
{
    if (!on) /* Reversed logic! */
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    setLed(false);
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
    Serial.print("\n\n\n");
    Serial.print("Blue Pill USB HID Keyboard started\n");
    Serial.print("Compiled on " __DATE__ " " __TIME__ "\n");
#endif
    Mouse.begin();
#if ENABLE_LCD
    Wire.begin();
    int r = u8g.begin();
#if ENABLE_SERIAL
    Serial.print("Display init: ");
    Serial.println(r);
#endif
    u8g.setFont(u8g_font_unifont);
#endif
}

void update_display()
{
#if ENABLE_LCD
    static uint32_t last_update_ms = 0;

    if (last_update_ms == 0 || last_update_ms + 500 <= millis())
    {
        last_update_ms = millis();
        u8g.setCursor(0, 0);
        if (Mouse.isPressed(MOUSE_LEFT))
        {
            u8g.print("B1");
        }
        else
        {
            u8g.print("  ");
        }

        u8g.setCursor(0, 22);
        if (mouse_press_end_ms)
        {
            u8g.print("RT: ");
            u8g.print((mouse_press_end_ms - millis()) / 1000);
            u8g.print(" s ");
        }
        else
        {
            u8g.print("RT: -      ");
        }
        u8g.sendBuffer();
    }
#endif
}

void loop()
{
    update_display();
    if (mouse_press_end_ms)
    {
        uint32_t m = millis();
        if (m > mouse_press_end_ms)
        {
#if ENABLE_SERIAL
            Serial.print("Press end due to timout\n");
#endif
            Mouse.release(MOUSE_LEFT);
            mouse_press_end_ms = 0;
        }
        if (((m + 1) % 1000) == 0)
        {
            if (random(0, 99) == 0)
            {
                if (random(0, 1) == 0)
                {
                    Mouse.move(random(-5, 5), 0);
                }
                else
                {
                    Mouse.move(0, random(-5, 5));
                }
            }
        }
    }
    if (digitalRead(KEY0_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key0 pressed\n");
#endif
        setLed(true);
        if (mouse_press_end_ms)
        {
#if ENABLE_SERIAL
            Serial.print("Increasing time\n");
#endif
            mouse_press_end_ms += mouse_press_time_ms;
        }
        else
        {
#if ENABLE_SERIAL
            Serial.print("Press start\n");
#endif
            Mouse.press(MOUSE_LEFT);
            mouse_press_end_ms = millis() + mouse_press_time_ms;
        }
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY0_PIN) == LOW);
        setLed(false);
    }
#if KEY_NUMBER > 1
    if (digitalRead(KEY1_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key1 pressed\n");
#endif
        if (mouse_press_end_ms)
        {
#if ENABLE_SERIAL
            Serial.print("Press end\n");
#endif
            Mouse.release(MOUSE_LEFT);
            mouse_press_end_ms = 0;
        }
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY1_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 2
    if (digitalRead(KEY2_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key2 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY2_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 3
    if (digitalRead(KEY3_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key3 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY3_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 4
    if (digitalRead(KEY4_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key4 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY4_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 5
    if (digitalRead(KEY5_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key5 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY5_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 6
    if (digitalRead(KEY6_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key6 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY6_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 7
    if (digitalRead(KEY7_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key7 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY7_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 8
    if (digitalRead(KEY8_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key8 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY8_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 9
    if (digitalRead(KEY9_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key9 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY9_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 10
    if (digitalRead(KEY10_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key10 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY10_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 11
    if (digitalRead(KEY11_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key11 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY11_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 12
    if (digitalRead(KEY12_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key12 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);
        /* Wait until releasing key */
        while (digitalRead(KEY12_PIN) == LOW);
    }
#endif
#if KEY_NUMBER > 13
    if (digitalRead(KEY13_PIN) == LOW)
    {
#if ENABLE_SERIAL
        Serial.print("Key13 pressed\n");
#endif
        delay(SOFTWARE_DEBOUNCE_TIME_MS);

        /* Wait until releasing key */
        while (digitalRead(KEY13_PIN) == LOW);
    }
#endif
}
