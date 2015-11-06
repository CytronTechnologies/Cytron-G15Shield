# setBaudRate() #

## Description ##
This function will set baudrate for G15 servo. User must ensure the controller and servo baudrate is match.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setBaudRate(servoID, uint32_t baudrate);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**baudrate**: 9600, 19200, 38400, 57600, 115200

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setBaudRate(1, 9600); // Set G15 with ID number 1 to new baudrate 9600
```