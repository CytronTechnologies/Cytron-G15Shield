# begin() #

## Description ##
Set the serial baudrate of Arduino board and begin the serial communication with G15. Make sure the baudrate is match with G15 baudrate. Default baudrate is 19200.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
begin(baudrate);
```

## Parameters ##
**baudrate**: 9600, 19200, 38400, 57600 or 115200. Default baudrate is 19200.

## Returns ##
None

## Example ##
```c
g15.begin(19200);
```
