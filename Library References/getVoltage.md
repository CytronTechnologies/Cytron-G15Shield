# getVoltage() #

## Description ##
This function retrieve the current voltage of the servo.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t getVoltage(servoID, uint8_t *data);
```

## Parameters ##
**servoID**: G15's servo ID<br/>
**data**: Pointer to an array to keep the retrieved data. At least 2 bytes size of array need to be declared first.

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
word status, load = 0;
byte data[2];
status = g15.getVoltage(1, data); // Read current voltage from G15 with ID number 1
load = data[0];
load = load | (word)(data[1] << 8);
```

## See Also ##
Return Status