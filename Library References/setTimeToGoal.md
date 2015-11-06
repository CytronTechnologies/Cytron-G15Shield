# setTimeToGoal() #

## Description ##
This function is to set G15 to move to goal position in a defined time frame. The actual time to reach the goal position can be affected if the G15's power is inadequate.<br/>
This is an alternative way to set the rotation speed of G15 Cube Servo.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setTimeToGoal(servoID, uint16_t time);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**time**: 1 to 4095 which represents 0.1 seconds to 409.5 seconds.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setTimeToGoal(1, 200); // Set G15 with ID number 1 with time to goal position 200 seconds
```