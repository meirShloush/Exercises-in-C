#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "string.h"
#include "func.h"


int main()
{
	int tmp1;
	int tmp2;
	int *ptr1;
	int *ptr2;
	
	char *str1;
	char *str2; 
	char *str3;
	char str99[100] = "   This      is    www    tutorial spoint    com    website   ";
	char str9[20];
	/* IsPalindrome */
	str1 = "meiriem";
	printf("%s is %i\n", str1, IsPalindrome(str1));
	
	str1 = "meirtiem";
	printf("%s is %i\n", str1, IsPalindrome(str1));
	
	
	/* Boom_seven */
	Boom_seven(10, 50);
	
	
	/* Rm Spaces */
	printf("\nRmSpaces\n\n");
	printf("%s\n", str99);
	RmSpaces(str99);
	printf("%s\n", str99);
	
	
	/* RmSpaces */
	printf("\nRmSpaces\n\n");
	tmp1 = 5;
	tmp2 = 10;
	ptr1 = &tmp1;
	ptr2 = &tmp2;
	

	/* SwapPointers */
	printf("tmp1 = %i, tmp2 = %i\n", *ptr1, *ptr2 );
	printf("tmp1 = %p, tmp2 = %p\n", (void *) ptr1, (void *)ptr2 );
	SwapPointers(&ptr1, &ptr2);
	printf("tmp1 = %i, tmp2 = %i\n", *ptr1, *ptr2 );
	printf("tmp1 = %p, tmp2 = %p\n", (void *)ptr1, (void *)ptr2 );
	
	printf("*& = %p\n", (void *)*&ptr2 );
	
	/* string plus string */
	printf("\nStr_plus_str\n\n");
	str1 = "765439";
	str2 = "9876";
	str3 = Str_plus_str(str1, str2);
	printf("%s\n + \n%s\n = \n%s\n",str1, str2, str3);
	free(str3);
	
	
	tmp1 = sizeof(str9);
	tmp2 = strlen(str9);
	
	printf("%i\n", tmp1);	
	printf("%i\n", tmp2);
	
	


	return (0);
}







int IsPalindrome(const char *str)
{
	int i = 0;
	int str_len = strlen(str);
	
	for(i = 0; i < (str_len / 2); i++)
	{
		if(*(str + i) != (*(str + str_len - 1 - i)))
		{
			return (0);
		}
	}
	return (1);
}


/******************************************************
recives num, and return 1 if have 7 in num, and 0 if haven't
*******************************************************/
int Have_seven(int num)
{
	while(num > 0)
	{
		if((num % 10) == 7)
		{
			return 1;
		}
		num/=10;
	}
	return (0);
}


void Boom_seven(int from, int to)
{
	while(from <= to)
	{
		if(Have_seven(from) || (from % 7) == 0)
		{
			printf("BOOM\n"); 	
		}
		else
		{
			printf("%i\n", from); 	
		}
		++from;
	}
}


void SwapPointers(int **ptr1, int **ptr2)
{
	int *tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}


void RmSpaces(char *str)
{
	char *run = str;
	
	/* clean apaces up to the first char */
	while(isspace(*run))
	{
		run++;
	}
	str = strcpy(str, run);
	
	/* run and str point to first arr */
	run = str;
	
	while('\0' != (*run))
	{
		if(isspace(*run) && isspace(*(run+1)))
		{
			++run;
		}
		else
		{
			*str++ = *run++;
		}
	}
	*str = '\0';
}

int Max(int num1, int num2)
{
	if(num1 > num2)
	{
		return (num1);
	}
	return (num2);
}

int Min(int num1, int num2)
{
	if(num1 > num2)
	{
		return (num2);
	}
	return (num1);
}

/* return pointer to a maximum str */
char* Max_str(char *str1, char* str2)
{
	int str_len1 = strlen(str1);
	int str_len2 = strlen(str2);
	
	if(str_len1 > str_len2)
	{
		return (str1);
	}
	return (str2);
}




char *Str_plus_str(char *str1, char* str2)
{
	int str_len1 = strlen(str1);
	int str_len2 = strlen(str2);
	int new_str_len = Max(str_len1, str_len2);
	int min_len = Min(str_len1, str_len2); 	
	int num1;
	int num2;
	int remainder = 0;
	int tmp;
	char* dest = malloc((new_str_len+1) * sizeof(char));
	int i = 0; 
	
	while(i < min_len)
	{ 
		num1 = *(str1 + str_len1 - i - 1)-48;
		num2 = *(str2 + str_len2 - i - 1)-48;
		tmp = (num1 + num2) % 10 + remainder;
		remainder = (num1 + num2) / 10;
		dest[i] = (tmp + 48) ;
		++i;
	}

	if(i == str_len1) 
	{
		while(i < str_len2)
		{ 
			num2 = *(str2 + str_len2 - i - 1)-48;
			tmp = (num2 + remainder) % 10;
			remainder = (num2 + remainder) / 10;
			dest[i] = (tmp + 48) ;
			++i;
		}
	}
	
	if(i == str_len2)
	{
		while(i < str_len1)
		{ 
			num1 = *(str1 + str_len1 - i - 1)-48;
			tmp = (num1 + remainder) % 10;
			remainder = (num1 + remainder) / 10;
			dest[i] = (tmp + 48) ;
			++i;
		}
	}
	
	if(0 < remainder)
		dest[i] = remainder ;
		
	for(i = 0; i < (new_str_len / 2); i++)
	{
		char enter = dest[i];
		*(dest + i) = *(dest + new_str_len - 1 - i);
		*(dest + new_str_len - 1 - i) = enter;
	}
	
		
	return(dest);
}



