

#include "Letters.h"


char Braile_Input(int word[])
{
	int inputVal,i=0,count=0;
	while(ReadBit(PINC,1) == 1)
	{
		if(ReadBit(PINC,0) == 0)
		{
			inputVal = ((~(PIND & 0xFF )) & 0b00111111 );
			word[i] = inputVal ;
			i++ ;
			count++;
			while(ReadBit(PINC,0) == 0);
		}
	}
	return count ;
}

char Braile_Interpreter (int decVal)
{
	char letter ;
	switch (decVal) {
	case 0 :
		letter = ' ';
		break;
	case 32 :
		letter = 'a';
		break;
	case 48 :
		letter = 'b';
		break;
	case 36 :
		letter = 'c';
		break;
	case 38 :
		letter = 'd';
		break;
	case 34 :
		letter = 'e';
		break;
	case 52 :
		letter = 'f';
		break;
	case 54 :
		letter = 'g';
		break;
	case 50 :
		letter = 'h';
		break;
	case 20 :
		letter = 'i';
		break;
	case 22 :
		letter = 'j';
		break;
	case 40 :
		letter = 'k';
		break;
	case 56 :
		letter = 'l';
		break;
	case 44 :
		letter = 'm';
		break;
	case 46 :
		letter = 'n';
		break;
	case 42 :
		letter = 'o';
		break;
	case 60 :
		letter = 'p';
		break;
	case 62 :
		letter = 'q';
		break;
	case 58 :
		letter = 'r';
		break;
	case 28 :
		letter = 's';
		break;
	case 30 :
		letter = 't';
		break;
	case 41 :
		letter = 'u';
		break;
	case 57 :
		letter = 'v';
		break;
	case 23 :
		letter = 'w';
		break;
	case 45 :
		letter = 'x';
		break;
	case 47 :
		letter = 'y';
		break;
	case 43 :
		letter = 'z';
		break ;
	default :
		letter = ' ' ;
	}
	return letter ;
}

void Word_Converter(int Bword[],char Eword[],int count)
{
	int i ;
	char let ;
	for(i=0; i<count; i++)
	{
		let = Braile_Interpreter(Bword[i]);
		strncat(Eword, &let, 1);
	}
}
void word_printer(char Eword[])
{
	
	LCD_WRITE_STRING(Eword);
}
