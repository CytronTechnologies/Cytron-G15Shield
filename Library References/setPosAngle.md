# setPosAngle() #

## Description ##
This function is to set G15's goal position in angle degree.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setPos(servoID, uint16_t angle);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**angle**: G15's goal angle position, starts from 0 to 359

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setPosAngle(1, 180); // Command G15 with ID number 1 to move to angle 180
```