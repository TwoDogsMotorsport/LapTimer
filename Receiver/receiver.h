//#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

#define _DEBUG              1
#define HISTORY_SIZE        32

// ========== CONFIGURE THIS ==========
#define EXPECTED_ID         0xA5      // must match the transmitter's BEACON_ID
#define IR_RECEIVE_PIN      2         // TSOP OUT pin (interrupt-capable recommended)

#define LCD_ROWS            4         // Available rows on LCD
#define LCD_COLS            20        // Available columns
#define LCD_ADDR            0x3F      // Default I2C address
// ====================================

unsigned long millisecs;
unsigned long startmillis;

/* The next part is experimental for now.
 *  Track a number of laps using a pre-defined
 *  block of memory
 */

unsigned long history[HISTORY_SIZE];
unsigned short history_counter;

void startClock(void);
void stopClock(void);
void calcTime(unsigned long worktime, unsigned int lap, unsigned int row);
