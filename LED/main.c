/*
 * LEDs
 * Author: OmarElsherif
 */

// Include libraries
#include <avr/delay.h>
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_Config.h"
#include "MCAL/DIO_Interface.h"

// Main function
void main(void)
{
	// Set port a direction as output
	DIO_VoidSetPortDirection(PORT_A, OUTPUT);

	// Program code
	while(1)
	{
		// Loop over port pins
		for(int i = 0; i < 8; i++)
		{
			// Turn on the led then delay for 500ms
			DIO_VoidSetPinValue(PORT_A, i, HIGH);
			_delay_ms(500);
		}

		// Reset all leds then delay for 500ms
		DIO_VoidSetPortValue(PORT_A, LOW);
		_delay_ms(500);
	}
}
