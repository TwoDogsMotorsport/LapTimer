/*
 * Simple IR Beacon Receiver
 * Listens for NEC frames and triggers when the address matches EXPECTED_ID.
 * Prints a message on Serial when a valid trigger is decoded.
 */

#include <IRremote.hpp>

// ========== CONFIGURE THIS ==========
#define EXPECTED_ID        0xA5      // must match the transmitter's BEACON_ID
#define IR_RECEIVE_PIN     2         // TSOP OUT pin (interrupt-capable recommended)
// ====================================

void setup() {
  Serial.begin(115200);
  while (!Serial);                   // wait for USB serial on some boards

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // LED_BUILTIN blinks on receive

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
