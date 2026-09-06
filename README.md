# INFRARED LAP TIMER FOR CIRCUIT RACING

## INTRODUCTION

This is far from an original idea, but I still wanted to do it my own way:

I take part in private track days as well as club sprint races, where the result is based on individual lap times rather than track position.

I can just go out an buy a solution, and if you want a properly built product go for it, but where is the fun in that?  Commercial systems are expensive, but you're paying for R&D tooling and potentially higher accuracy that you can get for yourself, while DIY lets you tailor the system to your requirements.

## CAN I BUILD THIS?

If you have some basic electronics skill and can work with hand tools, I think that's all you need.  I will leave the packaging up to you because everyone's needs are different, but it is pretty simple to get going

## SHOPPING LIST

### TRANSMITTER

1 x Arduino Nano
1 x 940nm Infra Red LED
1 x 180 ohm 1/4W resistor

For a longer range unit, you can use multiple LEDs and an N-Channel MOSFET to drive them  Look at https://learn.adafruit.com/rgb-led-strips/usage for an example

### RECEIVER

1 x Arduino Nano
1 x TSOP382 (or equivalent) Infra Red Receiver module
1 x 4-line x 20 character LCD display

