/*
 * LEDs
 * Author: OmarElsherif
 */

// Include libraries
#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

// Functions declarations
void turn_led(u8, u8, u8);
void led_by_led(u8 Port);

// Main function
void main(void)
{
	// Turn leds one by one on porta
	led_by_led(0);
}

// Function to turn on/off led
void turn_led(u8 Port, u8 Pin, u8 on_off)
{
	// Initialize Data Direction Register (DDR) for a specific bit
	DIO_VoidSetPinDirection(Port, Pin, 1);

	// Turn on led on the specific bit
	DIO_VoidSetPinValue(Port, Pin, on_off);

	// Program loop
	while(1){}
}

// Function to turn on leds one by one
void led_by_led(u8 Port)
{
	// Set port direction as output
	DIO_VoidSetPortDirection(Port, 0b11111111);

	// Program code
	while(1)
	{
		// Loop over port pins
		for(int i = 0; i < 8; i++)
		{
			// Turn on the led then delay for 500ms
			DIO_VoidSetPinValue(Port, i, 1);
			_delay_ms(500);
		}

		// Reset all leds then delay for 500ms
		DIO_VoidSetPortValue(Port, 0b00000000);
		_delay_ms(500);
	}

}

