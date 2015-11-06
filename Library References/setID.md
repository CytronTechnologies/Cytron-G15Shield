# setID() #

## Description ##
This function is to change a current servo ID to a new ID.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
uint16_t setID(servoID, uint8_t newID);
```

## Parameters ##
**servoID**: Current G15's servo ID<br/>
**newID**: New G15's servo ID that user want to change

## Returns ##
Error status in word. If return is non-zero, error occurred. Refer Return Status.

## Example ##
```c
g15.setID(1, 2); // Change current ID 1 to new ID 2
```