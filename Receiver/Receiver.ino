/*
 * Simple IR Beacon Receiver
 * Listens for NEC frames and triggers when the address matches EXPECTED_ID.
 * Prints a message on Serial when a valid trigger is decoded.
 */

#include "receiver.h"

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  int i = 0;
  
  Serial.begin(115200);
  while (!Serial);                   // wait for USB serial on some boards

  /* Boot up the LCD */
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Receiver Ready!");

  /* Start the IR module */
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // LED_BUILTIN blinks on receive

  /* Reset the time history */
  history_counter = 0;
  for(i=0; i < HISTORY_SIZE; i++)
    history[i] = 0;

  Serial.println(F("IR Beacon Receiver ready"));
  Serial.print(F("Looking for ID 0x"));
  Serial.println(EXPECTED_ID, HEX);
}

void loop() {
  if (IrReceiver.decode()) {
    // Only accept NEC protocol and exact address match
    if (IrReceiver.decodedIRData.protocol == NEC &&
        IrReceiver.decodedIRData.address == EXPECTED_ID) {

      Serial.print(F(">>> TRIGGER received – ID 0x"));
      Serial.print(IrReceiver.decodedIRData.address, HEX);
      Serial.print(F("  cmd 0x"));
      Serial.println(IrReceiver.decodedIRData.command, HEX);

      // Later you will start/stop your lap timer here
    }

    IrReceiver.resume();             // ready for the next frame
  }
}

void startClock(void) {
  startmillis = millis();
}

void stopClock(void) {
  millisecs = millis() - startmillis;
  /* Save the time */
  if (history_counter < (HISTORY_SIZE -1)) {
    history[history_counter] = millisecs;
    history_counter++;
  }
}

/* We have time to do all this
 * The display will look like:
 * nn hh:mm:ss.ms
 * where  nn  = lap #
 *        hhh = Hours
 *        mm  = Minutes
 *        ss  = Seconds
 *        ms  = Milliseconds
*/

void calcTime(unsigned long worktime, unsigned int lap, unsigned int row) {
  char buffer[LCD_COLS];
  unsigned long ms = worktime % 1000;
  unsigned long w_secs = worktime / 1000;
  unsigned long secs = w_secs % 60;
  unsigned long w_min = w_secs / 60;
  unsigned long mins = w_min % 60;
  unsigned long hrs = w_min / 60;

  if(row >=0 && row < LCD_ROWS) {
    lcd.setCursor(0, row);
    snprintf(buffer, sizeof(buffer), "%03d:%02d:%02d.%03d", hrs, mins, secs, ms);
    lcd.print(buffer);
  }
}
