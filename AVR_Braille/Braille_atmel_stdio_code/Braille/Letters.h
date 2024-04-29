

#ifndef LETTERS_H_
#define LETTERS_H_


#include "MemMap.h"
#include "string.h"
#include "Lcd.h"
#include "Utilites.h"

int decVal ;

typedef struct {
	char let1 ;
	char let2 ;
	char let3 ;
	char let4 ;
	char let5 ;
	char let6 ;
	char let7 ;
	char let8 ;
	char let9 ;
}Word;

char Braile_Input(int[]);
char Braile_Interpreter (int);
void Word_Converter(int[],char[],int);
void word_printer(char[]);


#endif /* LETTERS_H_ */
