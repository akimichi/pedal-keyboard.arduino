#include <Arduino.h>
#include <Wire.h>
#include <Keyboard.h>
// #include "Keyboard.h"

#define PEDAL1_PIN   2
#define PEDAL2_PIN   3
#define PEDAL3_PIN   4

char ctrlKey = KEY_LEFT_CTRL;
char rightArrowKey = KEY_RIGHT_ARROW;
char leftArrowKey = KEY_LEFT_ARROW;
char esclKey = KEY_ESC;

// 右への画面移動
static void Pedal1Down(void)
{

  while(digitalRead(PEDAL1_PIN) == HIGH) {
    // do nothing until pin 2 goes low
    delay(300);
  }
  // delay(1000);
  // new document:
  Keyboard.press(ctrlKey);
  Keyboard.press(rightArrowKey);
  delay(100);
  Keyboard.releaseAll();
  // wait for new window to open:
  // delay(1000);
}

static void Pedal2Down(void)
{

  while(digitalRead(PEDAL2_PIN) == HIGH) {
    // do nothing until pin 2 goes low
    delay(300);
  }
  // delay(1000);
  // new document:
  Keyboard.press(esclKey);
  delay(100);
  Keyboard.releaseAll();
  // wait for new window to open:
  // delay(1000);
}

static void Pedal3Down(void)
{

  while(digitalRead(PEDAL3_PIN) == HIGH) {
    // do nothing until pin 2 goes low
    delay(300);
  }
  // delay(1000);
  // new document:
  Keyboard.press(ctrlKey);
  Keyboard.press(leftArrowKey);
  delay(100);
  Keyboard.releaseAll();
  // wait for new window to open:
  // delay(1000);
}

void setup() 
{
  // ペダルの初期化
  // make pin 2 an input and turn on the 
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(PEDAL1_PIN, INPUT_PULLUP);
  pinMode(PEDAL2_PIN, INPUT_PULLUP);
  pinMode(PEDAL3_PIN, INPUT_PULLUP);
  // キーボードの初期化

  Keyboard.begin();
  // Set pin to input
  /* pinMode(PEDAL1_PIN, INPUT); */
  /* pinMode(PEDAL2_PIN, INPUT); */
  /* // Enable pullup resistor */
  /* digitalWrite(PEDAL1_PIN, HIGH); */
  /* digitalWrite(PEDAL2_PIN, HIGH); */

  /* delay(1000); */
}

void loop(void) 
{
  /* ペダルの処理 */
  /* Pedal1Down(); */
  /* Pedal3Down(); */
  /* // Pedal2Down(); */
  /* delay(100); */

  static uint8_t pedal1StateLast = 0;
  static uint8_t pedal2StateLast = 0;
  static uint8_t pedal3StateLast = 0;
  uint8_t pedalState;

  pedalState = digitalRead(PEDAL1_PIN);
  if (pedalState != pedal1StateLast) {
    pedal1StateLast = pedalState;

    if (pedalState == 0) {
      Pedal1Down();
      delay(100);
      Keyboard.releaseAll();
    } else {
      /* Pedal1Up(); */
      delay(100);
    }
  }
  pedalState = digitalRead(PEDAL2_PIN);
  if (pedalState != pedal2StateLast) {
    pedal2StateLast = pedalState;

    if (pedalState == 0) {
      Pedal2Down();
      delay(100);
      Keyboard.releaseAll();
    } else {
      /* Pedal1Up(); */
      delay(100);
    }
  }
  pedalState = digitalRead(PEDAL3_PIN);
  if (pedalState != pedal3StateLast) {
    pedal3StateLast = pedalState;

    if (pedalState == 0) {
      Pedal3Down();
      delay(100);
      Keyboard.releaseAll();
    }
  }

  /* delay(100); */
}


