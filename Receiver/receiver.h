#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

// ========== CONFIGURE THIS ==========
#define EXPECTED_ID        0xA5      // must match the transmitter's BEACON_ID
#define IR_RECEIVE_PIN     2         // TSOP OUT pin (interrupt-capable recommended)
// ====================================

#define LCD_ROWS      4
#define LCD_COLS      20
#define LCD_ADDR      0x3F
