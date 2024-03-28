void dmxMode() {
  digitalWrite(wireless_en, HIGH);
if (digitalRead(button_up) == LOW) {
    delay(50);
    DMXAdress++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (DMXAdress > 512) {
      DMXAdress = 1;
    }
  }
  if (digitalRead(button_down) == LOW) {
    delay(50);
    DMXAdress--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (DMXAdress < 1) {
      DMXAdress = 512;
    }
  }
  /*
  RED
  GREEN
  BLUE
  WHITE
  DIM
  */
  int dimmer = dmx_slave.getChannelValue(5);
  analogWrite(red_dim, map(dmx_slave.getChannelValue(1), 0, 255, 0, dimmer));
  analogWrite(green_dim, map(dmx_slave.getChannelValue(2), 0, 255, 0, dimmer));
  analogWrite(blue_dim, map(dmx_slave.getChannelValue(3), 0, 255, 0, dimmer));
  analogWrite(white_dim, map(dmx_slave.getChannelValue(4), 0, 255, 0, dimmer));
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
    display.print("DMX-Adresse:");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(DMXAdress);
    display.display();
  }
if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(104, (DMXAdress / 2));
    delay(50);
    EEPROM.update(105, (DMXAdress % 2));
    delay(50);
    EEPROM.update(106, menue_state);
    delay(50);
    display.fillRect(30, 40, 50, 31, 0xFFFF);
    display.display();
    delay(500);
    digitalWrite(rx_tx_en, LOW);
    dmx_slave.setStartAddress(DMXAdress);
    dmx_slave.enable();
  }
}
void ApeLabs() {
  digitalWrite(wireless_en, HIGH);
if (digitalRead(button_up) == LOW) {
    delay(50);
    Ape_DMX_Group++;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (Ape_DMX_Group > 4) {
      Ape_DMX_Group = 1;
    }
  }
  if (digitalRead(button_down) == LOW) {
    delay(50);
    Ape_DMX_Group--;
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    if (Ape_DMX_Group < 1) {
      Ape_DMX_Group = 4;
    }
  }
  /*
  RED
  GREEN
  BLUE
  WHITE
  */
  analogWrite(red_dim, dmx_slave.getChannelValue(1));
  analogWrite(green_dim, dmx_slave.getChannelValue(2));
  analogWrite(blue_dim, dmx_slave.getChannelValue(3));
  analogWrite(white_dim, dmx_slave.getChannelValue(4));
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
    display.print("ApeLabs Gruppe:");
    display.setTextSize(3);
    display.setCursor(30, 40);
    display.print(Ape_DMX_Group);
    display.display();
  }
if (digitalRead(button_enter) == LOW) {
    delay(50);
    last_time = actual_time;
    if (display_enable == 0) {
      display_enable = 1;
    }
    EEPROM.update(111, Ape_DMX_Group);
    delay(50);
    EEPROM.update(106, menue_state);
    delay(50);
    display.fillRect(30, 40, 50, 31, 0xFFFF);
    display.display();
    delay(500);
    digitalWrite(rx_tx_en, LOW);
    switch (Ape_DMX_Group) {
      case 1:  //Group 1
        dmx_slave.setStartAddress(2);
        break;
      case 2:  //Group 2
        dmx_slave.setStartAddress(23);
        break;
      case 3:  //Group 3
        dmx_slave.setStartAddress(44);
        break;
      case 4:  //Group 4
        dmx_slave.setStartAddress(65);
        break;
      default:  //If error etc. group 1 default.
        dmx_slave.setStartAddress(2);
    }
    dmx_slave.enable();
  }
}
/*void DMXConfig ()
{
  if (digitalRead(button_up) == LOW)
  {
    num_of_channels = !num_of_channels;
    last_time = actual_time;
    if (display_enable == 0)
    {
      display_enable = 1;
    }
  }
  if (digitalRead(button_down) == LOW)
  {
    num_of_channels = !num_of_channels;
    last_time = actual_time;
    if (display_enable == 0)
    {
      display_enable = 1;
    }
  }
  switch (num_of_channels)
  {
    case 0: //4Channels
      DMXChannels = 4;
      break;
    case 1: //6Channels
      DMXChannels = 6;
      break;
    default:
      break;
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(50, 1);
  display.print(Uges);
  display.setCursor(98, 1);
  display.print(" V");
  display.setTextSize(1);
  display.setCursor(5, 20);
  display.print("DMX - Kanale");
  display.setTextSize(3);
  display.setCursor(30, 40);
  display.print(DMXChannels);
  display.display();
  if (digitalRead(button_enter) == LOW)
  {
    last_time = actual_time;
    if (display_enable == 0)
    {
      display_enable = 1;
    }
    EEPROM.update(107, DMXChannels);
    delay(50);
    EEPROM.update(108, num_of_channels);
    delay(50);
    EEPROM.update(106, menue_state);
    display.fillRect(30, 40, 50, 31, 0xFFFF);
    display.display();
    delay(500);
  }
}*/
