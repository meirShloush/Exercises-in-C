#include <stdio.h>
#include <stdbool.h>

int Flip(int);

int main()
{
	int num;
	
	printf("enter a number: ");
	scanf("%d", &num);
	printf("%i\n", Flip(num));

	return (0);
}

int Flip(int num)
{
	double result = 0; 
	bool positive = true;
	
	/* if the num < 0 is a negetive number */
	if (num < 0) 
	{
		positive = false;
		num = -num; /* look at the num as a positive number, and turn it back in the return */
	}
	while (num > 0)
	{
		result = result * 10 + num % 10; /* result = old result*10 + the last digit of the num */
		num /= 10;
	}
	if(!positive) /* turn it back to a negetive number */
	{ 
		result = -result; 
	}
	return (result);
}

