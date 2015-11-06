# setPosSpeed() #

## Description ##
This function is to set G15's goal position and moving speed.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setPosSpeed(servoID, uint16_t position, uint16_t speed);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**position**: G15's goal angle position, starts from 0 to 1087<br/>
**speed**: G15's moving speed, starts from 0 to 1023

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setPosSpeed(1, 1000, 500); // Command G15 with ID number 1 to move to position 1000 with moving speed 500
g15.setPosSpeed(1, ConvertAngleToPos(180), 1000); // Command G15 with ID number 1 to move to angle 180 with moving speed 1000
```