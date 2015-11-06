# getPos() #

## Description ##
This function retrieve the current position of the servo. The position is in the range from 0 to 1087.<br/>
Use ConvertPos2Angle() macro to convert to angle value in degree. The macro return value in float format.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t getPos(servoID, uint8_t *data);
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
status = g15.getPos(1, data); // Read current position from G15 with ID number 1
load = data[0];
load = load | (word)(data[1] << 8);
```

## See Also ##
Return Status