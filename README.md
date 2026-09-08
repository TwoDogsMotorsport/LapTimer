# INFRARED LAP TIMER FOR CIRCUIT RACING

## INTRODUCTION

This is far from an original idea, but that doesn't mean you shouldn't have a go.

We take part in private track days as well as club sprint races, where the result is based on individual lap times rather than track position.

The benefit here is that you can tailor this system to suit your needs.  Want to store more laps, add a bigger display allow downloads?  All these things are possible.

While this looks a fair bit like the AIM or Motec displays, it is not compatible with them, and if we've done our homework properly our system and theirs happily ignore each other.  If not, please raise an issue.

## CAN I BUILD THIS?

If you have some basic electronics skill and can work with hand tools, I think that's all you need.  I will leave the packaging up to you because everyone's needs are different, but it is pretty simple to get going

## SHOPPING LIST

### TRANSMITTER

* 1 x Arduino Nano
* 1 x 940nm Infra Red LED
* 1 x 180 ohm 1/4W resistor

For a longer range unit, you can use multiple LEDs and an N-Channel MOSFET to drive them  Look at https://learn.adafruit.com/rgb-led-strips/usage for an example.  The included schematic shows four LEDs using a MOSFET, but you could run more (or less) if you want.

### RECEIVER

* 1 x Arduino Nano
* 1 x TSOP382 (or equivalent) Infra Red Receiver module
* 1 x 4-line x 20 character LCD display

