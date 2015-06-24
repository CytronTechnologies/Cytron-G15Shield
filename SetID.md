# SetID() #

## Description ##
This function set a new ID for the servo. After successful setting, the servo ID is updated to NewID.

## Include ##
G15.h

## Prototype ##
word SetID(byte NewID);

## Parameters ##
**NewID**:

## Returns ##
Error status in word. If return is non-zero, error occurred.

## Example ##
word stat;

stat = servo1.SetID(5);  //set servo1's ID to 5.

## See Also ##
ReturnStatus