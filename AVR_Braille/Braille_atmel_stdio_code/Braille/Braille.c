/*
 * Braille.c
 *
 * Created: 2/5/2024 6:30:07 PM
 *  Author: salah soliman
 */ 


#include "Letters.h"
#define F_CPU 8000000UL

void IO_init(void)
{
	//Output Init	
	
	//Input Init
	
	//Configure PortD as Input Port
	DDRD = 0x00;
	//Configure PortD Pin0 as Input Pin
	ClearBit(DDRC,0);
	ClearBit(DDRC,1);
	ClearBit(DDRC,2);
	
	//init PortC Pin0 and PortD as Pull up Input Pin
	//SetBit(PORTC,0) ;
	SetBit(PORTC,0);
	SetBit(PORTC,1);
	SetBit(PORTC,2);
	PORTD = 0xFF ;
}
int main(void)
{
	IO_init();
	LCD_INIT();
	
    while(1)
    {
		int Brailleword[100],count;
		char Englishword[100]="";
		/*
		int Brailleword[100]={28,32,56,32,50},count=5;
		char Englishword[100]="";
		*/
		count = Braile_Input(Brailleword);
		Word_Converter(Brailleword,Englishword,count);
		word_printer(Englishword);
		while(ReadBit(PINC,2) == 1);
		LCD_clear_screen();
    }
}