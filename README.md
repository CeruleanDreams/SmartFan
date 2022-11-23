# SmartFan
A smart fan, for smart people.


This project implements PWM to regulate the RPM of the fan in use. The "smartness" of the fan comes from its autonomy in determining the temperature and its automatic adjustment. It only deploys when the temperature is beyond the sweet spot, and ramps up until coming to a halt whenever wind convection becomes redundant (after 37 degrees Celsius).

This project makes use of an STM32 F401RE Nucleo Board; the Arduino IDE was used to implement the code in C.
