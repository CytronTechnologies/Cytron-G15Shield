# setVoltageLimit() #

## Description ##
This function is to set G15 to wheel mode which able to rotate continously in the defined direction.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setWheelMode(servoID);
```

## Parameters ##
**servoID**: G15's servo ID

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setWheelMode(1); // Set G15 with ID number 1 to wheel mode
```