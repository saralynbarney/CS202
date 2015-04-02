#include "stringlibrary.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// This is string compare


bool stringcompare(char *string1, char *string2)
{
int i;
	bool equals=true;
		while(*string1 !='\0' && *string2 !='\0' && *string1==*string2){		
			if(*string1 != *string2){
				equals = false;
			}
				string1++;
				string2++;			
			}
        if(*string1!=*string2){
				equals = false;
		 								}			
return equals;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//This is string copy


void stringcopy( char *dest, char *source)
{

	while (*source != '\0')
	{
	(*dest)=(*source);
	dest++;
	source++;
	}
	*dest = '\0';

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// This is string concatenation

void stringconcatenation(char *string1 , char *string2)
{
	while(*string1 != '\0')
	{
		string1++ ;
	}
	while(*string2 != '\0')
	{
		*string1++ = *string2++ ;
	}
*string1 = '\0';
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// This is string length


int stringlength(char * str)
{
int words=0;
char * p = str;
	while(*p != '\0'){
	words++;
	p++;
					 }
return words;
}

