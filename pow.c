#include <stdio.h>
#include <stdbool.h>

float Pow_of_10(int);

int main()
{
	int num = 4;

	printf("enter a number: ");
	scanf("%d", &num);
	printf("10 ^ %i = %f\n", num, Pow_of_10(num));
	return (0);
}


/* this function recives a num, and return 10^num */
float Pow_of_10(int num)
{
	float result = 1;
	bool positive = true; 

	/* if the num < 0 is a negetive number */
	if (num < 0) 
	{
		positive = false;
		num = -num; /* look at the num as a positive number, and turn it back in the return */
	}
	while (num > 0)
	{
		result *= 10;
		num--;
	}
	if (!positive)
	{
		result = 1 / result; /* the result of 10 ^ negetive number is 1/(10^num) */
	}
	return (result);
}
