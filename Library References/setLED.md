# setLED() #

## Description ##
This function is to control the G15's LED.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setLED(servoID, uint8_t onOff);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**onOff**: ON to turn on the G15's LED, OFF to turn off the G15's LED

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setLED(1, ON); // Turn on LED for G15 with ID number 1
delay(1000);
g15.setLED(1, OFF); // Turn off LED for G15 with ID number 1
delay(1000);
```