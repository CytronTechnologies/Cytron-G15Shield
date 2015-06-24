# G15ShieldInit() #

## Description ##
Set the serial baudrate of Arduino board and begin the serial communication. Then the function configures the control pins for G15 shield as digital outputs and set ports to TX mode.

## Include ##
G15.h

## Prototype ##
G15ShieldInit(long baud, char G15\_CTRL, char AX12\_CTRL);

## Parameters ##
**baud**: Arduino serial baudrate (eg: 9600, 19200, 38400, 57600 or 115200; also tested to run at 500k without any issue.)

**G15\_CTRL**: control pin for G15 port (3 or 9)

**AX12\_CTRL**: control pin for AX12 port (2 or 8)


## Returns ##
None

## Example ##
G15ShieldInit(19200, 3, 8);
//initialize the Arduino serial to 19200 baudrate and configure the control pins to 3(G15 port) and 8(AX12 port).