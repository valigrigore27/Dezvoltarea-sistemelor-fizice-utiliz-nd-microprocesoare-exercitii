#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // Citește linia trimisă prin portul serial
    String received_line = Serial.readStringUntil('\n');

    // Afisează linia pe ecranul LCD
    lcd.clear();
    lcd.print(received_line);
    delay(2000);  // Afișează timp de 2 secunde (poate fi modificat)

    // Poți adăuga aici și alte acțiuni în funcție de nevoile tale
  }
}
