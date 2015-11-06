# setPos() #

## Description ##
This function is to set G15's goal position.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setPos(servoID, uint16_t position);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**position**: G15's goal position, starts from 0 to 1087

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setPos(1, 1000); // Command G15 with ID number 1 to move to position 1000
g15.setPos(1, ConvertAngleToPos(180)); // Command G15 with ID number 1 to move to angle 180
```