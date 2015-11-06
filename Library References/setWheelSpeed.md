# setWheelSpeed() #

## Description ##
This function is to set G15's rotation speed and direction in wheel mode.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setWheelSpeed(servoID, uint16_t speed, uint8_t direction);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**speed**: Rotation speed, 0 to 1023<br/>
**direction**: CW for clockwise, CCW for counter-clockwise

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setWheelSpeed(1, 800, CW); // Set G15 with ID number 1 to continuous rotate with speed 800 in clockwise direction
```