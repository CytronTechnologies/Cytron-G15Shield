# setTorqueOnOff() #

## Description ##
This function turns the servo torque on or off. When turned on, the servo will hold it's shaft in position. When turned off the shaft can be freely turned by hand.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setTorqueOnOff(servoID, uint8_t onOff);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**onOff**: ON or OFF

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setTorqueOnOff(1, ON); // Enable torque for G15 with ID number 1
```