/*
 * CFile1.c
 *
 * Created: 29.09.2024 17:26:04
 *  Author: uwmpr
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "SSD1306.h"
uint32_t count;
void timer_init(){
	TCCR1B |= (1<<WGM12);
	OCR1A = (F_CPU/1024);
	TCCR1B |= (1 << CS12) | (1 << CS10);
	TIMSK1 |= (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect){
	count++;
	OLED_Clear();
	OLED_SetCursor(0, 0);        //set the cursor position to (0, 0)
	OLED_DisplayNumber(10, count, ((log10 (abs (count))) + 1));
}
int main(void) {
	
	OLED_Init();  //initialize the OLED
	OLED_Clear(); //clear the display (for good measure)
	timer_init();
	sei();
	while (1) {
		
		

	}
	
	return 0; // never reached
}