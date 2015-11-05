# Cytron_G15Shield #

## Description ##
This is the constructor for the Cytron_G15Shield class.

## Include ##
Cytron_G15Shield.h

## Prototype ##
Cytron_G15Shield(ctrlPin); // For hardware serial
Cytron_G15Shield(rxPin, txPin, ctrlPin); // For software serial

## Parameters ##
**rxPin**: G15's receive pin
**txPin**: G15's transmit pin
**ctrlxPin**: G15's control pin

## Returns ##
None

## Example ##
Cytron_G15Shield g15(8); // for hardware serial: Control pin
Cytron_G15Shield g15(2, 3, 8); // For software serial: Rx, Tx and Control pin
