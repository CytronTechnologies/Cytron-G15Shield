# setSpeed() #

## Description ##
This function is to set G15's moving speed.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setSpeed(servoID, uint16_t speed);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**speed**: G15's moving speed, starts from 0 to 1023

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setSpeed(1, 1000); // Set G15 with ID number 1 with moving speed 1000
```