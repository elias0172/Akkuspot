void manualRed() {
  if (digitalRead(button_up) == LOW) {
    delay(50);
    red_value++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (digitalRead(button_down) == LOW) {
    delay(50);
    red_value--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (display_enable == 1) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(50, 1);
    display.print(Uges);
    display.setCursor(98, 1);
    display.print(" V");
    display.setTextSize(1);
    display.setCursor(5, 20);
    display.print("Manuell-Rot");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(red_value);
    display.display();
  }
  if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(100, red_value);
    delay(50);
    EEPROM.update(106, menue_state);
    delay(50);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
}
void manualGreen() {
  if (digitalRead(button_up) == LOW) {
    delay(50);
    green_value++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (digitalRead(button_down) == LOW) {
    delay(50);
    green_value--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (display_enable == 1) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(50, 1);
    display.print(Uges);
    display.setCursor(98, 1);
    display.print(" V");
    display.setTextSize(1);
    display.setCursor(5, 20);
    display.print("Manuell-Gr\201n");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(green_value);
    display.display();
  }
  if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(101, green_value);
    delay(50);
    EEPROM.update(106, menue_state);
    delay(50);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
}
void manualBlue() {
  if (digitalRead(button_up) == LOW) {
    delay(50);
    blue_value++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (digitalRead(button_down) == LOW) {
    delay(50);
    blue_value--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (display_enable == 1) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(50, 1);
    display.print(Uges);
    display.setCursor(98, 1);
    display.print(" V");
    display.setTextSize(1);
    display.setCursor(5, 20);
    display.print("Manuell-Blau");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(blue_value);
    display.display();
  }
  if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(102, blue_value);
    delay(50);
    EEPROM.update(106, menue_state);
    delay(50);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
}
void manualWhite() {
  if (digitalRead(button_up) == LOW) {
    delay(50);
    white_value++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (digitalRead(button_down) == LOW) {
    delay(50);
    white_value--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
  if (display_enable == 1) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(50, 1);
    display.print(Uges);
    display.setCursor(98, 1);
    display.print(" V");
    display.setTextSize(1);
    display.setCursor(5, 20);
    display.print("Manuell-Weiss");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(white_value);
    display.display();
  }
  if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(103, white_value);
    delay(50);
    EEPROM.update(106, menue_state);
    delay(50);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
}
