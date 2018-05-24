#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int x = 0;
int TPressed()
{
	printf("T pressed\n");
	return (0);
}


int APressed()
{
	printf("A pressed\n");
	return (0);
}


int Esc()
{
	return (1);
}


int main(int argc, char **argv)
{
	int (*ptr_function[256])(void);
	int flag = 0;
	int c = 0;
	int i = 0;
	
	for(i = 0; i < 256; ++i)
	{
		*(ptr_function + i) = NULL;
	}

	*(ptr_function + 65) = APressed;
	*(ptr_function + 84) = TPressed;
	*(ptr_function + 27) = Esc;
	
	/* stop terminal buffering and echoing */	
	system("stty -icanon -echo");
		
	while(!flag)
	{	
		c = getchar();
		if ( NULL != *(ptr_function + c) )
		{
			flag = (*(ptr_function + c))();	
		}
	}
	/* return terminal to its default state */
	system("stty icanon echo");	
	
	return (0);
}




