void low_battery() {
  display.clearDisplay();
  display.setCursor(20, 5);
  display.print("!LOW!");
  display.setCursor(0, 30);
  display.print("BATTERY");
  display.display();
  analogWrite(red_dim, 0);
  analogWrite(green_dim, 0);
  analogWrite(blue_dim, 0);
  analogWrite(white_dim, 0);
}
