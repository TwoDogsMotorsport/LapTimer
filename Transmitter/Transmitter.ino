/*
 * Simple IR Beacon Transmitter
 * Continuously sends an 8-bit ID using NEC protocol.
 */

#include "transmitter.h"

void setup() {
  Serial.begin(115200);
  IrSender.begin(IR_SEND_PIN);
  Serial.print(F("Beacon TX started – ID = 0x"));
  Serial.println(BEACON_ID, HEX);
}

void loop() {
  // Address = our ID, Command = fixed marker (you can also put data in command)
  IrSender.sendNEC(BEACON_ID, 0x01, 0);   // 0 repeats for a clean single frame

  delay(SEND_INTERVAL_MS);
}
