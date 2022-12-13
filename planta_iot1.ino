// C++ code
//
#include "Adafruit_LEDBackpack.h"

#include <Adafruit_LiquidCrystal.h>

int humidade = 0;

Adafruit_7segment led_display1 = Adafruit_7segment();

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  led_display1.begin(112);
  lcd_1.begin(16, 2);
}

void loop()
{
  humidade = analogRead(A0);
  Serial.println(humidade);
  if (humidade < 500) {
    led_display1.clear();
    led_display1.writeDisplay();
    lcd_1.print("PRECISO DE AGUA");
    lcd_1.setCursor(0, 0);
  } else {
    led_display1.clear();
    led_display1.writeDisplay();
    lcd_1.print("ESTOU HIDRATADO");
    lcd_1.setCursor(0, 0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}