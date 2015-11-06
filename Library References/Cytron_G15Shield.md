# Cytron_G15Shield #

## Description ##
This is the constructor for the Cytron_G15Shield class.

## Include ##
Cytron_G15Shield.h

## Prototype ##
```c
Cytron_G15Shield(ctrlPin); // For hardware serial
Cytron_G15Shield(rxPin, txPin, ctrlPin); // For software serial
```

## Parameters ##
**rxPin**: G15's receive pin<br/>
**txPin**: G15's transmit pin<br/>
**ctrlxPin**: G15's control pin

## Returns ##
None

## Example ##
```c
Cytron_G15Shield g15(8); // for hardware serial: Control pin
Cytron_G15Shield g15(2, 3, 8); // For software serial: Rx, Tx and Control pin
```