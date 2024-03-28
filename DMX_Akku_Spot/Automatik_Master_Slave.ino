void automatic() {

  if (digitalRead(button_up) == LOW) {
    delay(50);
    fadePause++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
  }
   if (digitalRead(button_down) == LOW) {
    delay(50);
    fadePause--;
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
    display.print("Automatik");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(fadePause);
    display.display();
  }
   if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(106, menue_state);
    delay(50);
    EEPROM.update(110, fadePause);
    delay(50);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
  if (EEPROM.read(106) == 6) {
    dmx_slave.disable();
    // Blaue LED beim ersten Durchlauf einblenden
    if (ersterLauf == true && millis() - fadeZeit > fadePause) {
      // Wenn b kleiner als 255 ist...
      if (b < 255) {
        b++;                       // Zählt b um 1 hoch
        analogWrite(blue_dim, b);  // Ausganbe von b am LED Pin
        fadeZeit = millis();       // Aktuelle Zeit speichern
      }

      // Wenn b bei 255 angekommen UND die halteZeit vergangen ist...
      if (b == 255 && (millis() - fadeZeit) > (fadePause + halteZeit)) {
        ersterLauf = false;  // Erster Lauf ist abgeschlossen
      }
    }

    // Wenn ersterLauf abgeschlossen ist UND fadePause vergangen ist...
    if (ersterLauf == false && millis() - fadeZeit > fadePause) {
      // Wechsel von Blau zu Lila
      if (farbe == 'b') {
        // Wenn r kleiner als 255 ist...
        if (r < 255) {
          r++;                      // Zählt r um 1 hoch
          analogWrite(red_dim, r);  // Ausganbe von r am LED Pin
          fadeZeit = millis();      // Aktuelle Zeit speichern
        }

        // Wenn r bei 255 angekommen UND die halteZeit vergangen ist...
        if (r == 255 && millis() - fadeZeit > fadePause + halteZeit) {
          farbe = 'l';  // Ändere Frabe auf "l" (Lila)
        }
      }

      // Wechsel von Lila zu Rot
      if (farbe == 'l') {
        // Wenn b größer als 0 ist...
        if (b > 0) {
          b--;                       // Zählt b um 1 runter
          analogWrite(blue_dim, b);  // Ausganbe von b am LED Pin
          fadeZeit = millis();       // Aktuelle Zeit speichern
        }

        // Wenn b bei 0 angekommen UND die halteZeit vergangen ist...
        if (b == 0 && millis() - fadeZeit > fadePause + halteZeit) {
          farbe = 'r';  // Ändere Frabe auf "r" (Rot)
        }
      }

      // Wechsel von Rot zu Gelb
      if (farbe == 'r') {
        // Wenn g kleiner als 255 ist...
        if (g < 255) {
          g++;                        // Zählt g um 1 hoch
          analogWrite(green_dim, g);  // Ausganbe von g am LED Pin
          fadeZeit = millis();        // Aktuelle Zeit speichern
        }

        // Wenn g bei 255 angekommen UND die halteZeit vergangen ist...
        if (g == 255 && millis() - fadeZeit > fadePause + halteZeit) {
          farbe = 'y';  // Ändere Frabe auf "y" (Gelb)
        }
      }

      // Wechsel von Gelb zu Gruen
      if (farbe == 'y') {
        // Wenn r größer als 0 ist...
        if (r > 0) {
          r--;                      // Zählt r um 1 runter
          analogWrite(red_dim, r);  // Ausganbe von r am LED Pin
          fadeZeit = millis();      // Aktuelle Zeit speichern
        }

        // Wenn r bei 0 angekommen UND die halteZeit vergangen ist...
        if (r == 0 && millis() - fadeZeit > fadePause + halteZeit) {
          farbe = 'g';  // Ändere Frabe auf "g" (Grün)
        }
      }

      // Wechsel von Gruen zu Petrol
      if (farbe == 'g') {
        // Wenn b kleiner als 255 ist...
        if (b < 255) {
          b++;                       // Zählt b um 1 hoch
          analogWrite(blue_dim, b);  // Ausganbe von b am LED Pin
          fadeZeit = millis();       // Aktuelle Zeit speichern
        }

        // Wenn b bei 255 angekommen UND die halteZeit vergangen ist...
        if (b == 255 && millis() - fadeZeit > fadePause + halteZeit) {
          farbe = 'p';  // Ändere Frabe auf "p" (Petrol)
        }
      }

      // Wechsel von Petrol zu Blau
      if (farbe == 'p') {
        // Wenn g größer als 0 ist...
        if (g > 0) {
          g--;                        // Zählt g um 1 runter
          analogWrite(green_dim, g);  // Ausganbe von g am LED Pin
          fadeZeit = millis();        // Aktuelle Zeit speichern
        }

        // Wenn g bei 0 angekommen UND die halteZeit vergangen ist...
        if (g == 0 && millis() - fadeZeit > fadePause + halteZeit) {
          farbe = 'b';  // Ändere Frabe auf "b" (Blau)
        }
      }
    }
  }
}

void farbe_menu() {
   if (digitalRead(button_up) == LOW) {
    delay(50);
    farben++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (farben > 8) {
      farben = 0;
    }
  }
   if (digitalRead(button_down) == LOW) {
    delay(50);
    farben--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (farben < 0) {
      farben = 8;
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
    display.print("Farbe:");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(farben);
    display.display();
  }
   if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(106, menue_state);
    delay(50);
    EEPROM.update(109, farben);
    delay(50);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
  if (EEPROM.read(106) == 7) {
    dmx_slave.disable();
    switch (farben) {
      case 0:  //Rot
        //farbe_name[1] = "Rot";
        red_value = 255;
        green_value = 0;
        blue_value = 0;
        white_value = 0;
        break;
      case 1:  //Orange
        //farbe_name[1] = "Orange";
        red_value = 255;
        green_value = 150;
        blue_value = 0;
        white_value = 0;
        break;
      case 2:  //Gelb
        //farbe_name[1] = "Gelb";
        red_value = 255;
        green_value = 189;
        blue_value = 0;
        white_value = 0;
        break;
      case 3:  //Grün
        //farbe_name[1] = "Grun";
        red_value = 0;
        green_value = 255;
        blue_value = 0;
        white_value = 0;
        break;
      case 4:  //Aquamarin
        //farbe_name[1] = "Aquamarin";
        red_value = 0;
        green_value = 255;
        blue_value = 28;
        white_value = 0;
        break;
      case 5:  //Türkis
        //farbe_name[1] = "Turkis";
        red_value = 0;
        green_value = 206;
        blue_value = 209;
        white_value = 0;
        break;
      case 6:  //Blau
               // farbe_name[1] = "Blau";
        red_value = 0;
        green_value = 0;
        blue_value = 255;
        white_value = 0;
        break;
      case 7:  //Weiß
               // farbe_name[1] = "Weiss";
        red_value = 0;
        green_value = 0;
        blue_value = 0;
        white_value = 255;
        break;
      case 8:  //Pink
               // farbe_name[1] = "Pink";
        red_value = 255;
        green_value = 0;
        blue_value = 255;
        white_value = 0;
        break;
      default:  //OFF
                // farbe_name[1] = "OFF";
        red_value = 0;
        green_value = 0;
        blue_value = 0;
        white_value = 0;
        break;
    }
  }
}

/*void Slave()
  {
  //  dmx_master.disable ();
  if (digitalRead(button_up) == LOW)
  {
    slave_enable = !slave_enable;
    last_time = actual_time;
    if (display_enable == 0)
    {
      display_enable = 1;
    }
  }
  if (digitalRead(button_down) == LOW)
  {
    slave_enable = !slave_enable;
    last_time = actual_time;
    if (display_enable == 0)
    {
      display_enable = 1;
    }
  }
  switch (slave_enable)
  {
    case 0: //OFF
      if (display_enable == 1)
      {
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(2);
        display.setCursor(50, 1);
        display.print(Uges);
        display.setCursor(98, 1);
        display.print(" V");
        display.setTextSize(1);
        display.setCursor(5, 20);
        display.print("Slave");
        display.setTextSize(3);
        display.setCursor(30, 40);
        display.print("OFF");
        display.display();
      }
      dmx_slave.disable ();
      break;
    case 1: //ON
      if (display_enable == 1)
      {
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(2);
        display.setCursor(50, 1);
        display.print(Uges);
        display.setCursor(98, 1);
        display.print(" V");
        display.setTextSize(1);
        display.setCursor(5, 20);
        display.print("Slave");
        display.setTextSize(3);
        display.setCursor(30, 40);
        display.print("ON");
        display.display();
      }
      dmx_slave.setStartAddress (1);
      dmx_slave.enable ();
      digitalWrite(rx_tx_en, LOW);
      analogWrite(red_dim, dmx_slave.getChannelValue (1));
      analogWrite(green_dim, dmx_slave.getChannelValue (2));
      analogWrite(blue_dim, dmx_slave.getChannelValue (3));
      analogWrite(white_dim, dmx_slave.getChannelValue (4));
      break;
    default:
      break;
  }
  if (digitalRead(button_enter) == LOW)
  {
    last_time = actual_time;
    if (display_enable == 0)
    {
      display_enable = 1;
    }
    EEPROM.update(109, slave_enable);
    delay(50);
    EEPROM.update(106, menue_state);
    display.fillRect(30, 40, 50, 32, 0xFFFF);
    display.display();
    delay(500);
  }
  }
*/
