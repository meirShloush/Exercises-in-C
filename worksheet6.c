#include <stdio.h>


int CountBits(int num);

/* resived x and y, and return x*(2^y) */
float Pow2 (unsigned int x, int y)
{ 
	if(y > 0)
	{
		return(x << y);	
	}
	return ((float) x / (1 << (-y)));
}


/* return 1 if num is power of 2 */
int PowOfTwo(int num)
{
	return ( (CountBits(num) == 1) ? 1 : 0);
}

/* return 1 if num is power of 2 */
int PowOfTwo2(int num)
{
	return (num & (~(-num)) ? 0 : 1);
}


/* resived num, and return num + 1  */
int AddOne(int num)
{
	int i = 1;
	
	while (i & num)
	{
		num = num ^ i;
		i <<= 1;
	}
	
	return (num ^ i);
}


/* resived num, and return num + 1  */
int AddOne2(int num)
{
	return(-(~num));
}


/* resived num, and return  */
int Closets(unsigned int num)
{
	num >>= 4;
	num <<= 4;
	
	return (num);
}

/* resived 2 pointers, and swap between them */
void Swap(int *x, int *y)
{
	*x = (*x) ^ (*y);
	*y = (*x) ^  (*y);
	*x = (*x) ^ (*y);
}

/* count how much bits is set on in integer */
int CountBits(int num)
{
	int counter = 0;
	
	while (num)
	{
		if (1 & num)
		{
			counter++;		
		}	
		num>>=1;
	}
	
	return (counter);
}



/*
int CountBits2(int num)
{
	if(num == 0)
		return (0);
	
	if (1 & num)
	{
		return (CountBits(num >> 1) + 1);
	}	
	
	return (CountBits(num >> 1));
}
*/


/* return true if bit 2 and 6 set on */
int BitsTwoAndSixOn(int num)
{
	return ( ((num & 32) && (num & 2))  ? 1 : 0 ) ;
} 


/* return true if bit 2 or 6 set on */
int BitsTwoOrSixOn(int num)
{
	return ( ((num & 2) || (num & 32)) ? 1 : 0 );
} 


/* swap between bit 3 and 5 */
int SwapBitThreeAndFive(int num)
{	
	/* save bits 1,2,4 */
	int bits124 = (num & 11);
	
	/* save bit 3 */	
	int bit3 = (num & 4) ;

	/* save bit 5 */		
	int bit5 = (num & 16) ;
	
	/* swap */
	bit3 <<= 2 ;
	bit5 >>= 2 ;	
	
	num >>=5;
	num <<=5;
	
	num |= bit3;
	num |= bit5;
	num |= bits124;

	return (num);
}


/* resived an arr of int, and print all int's that have exactly 3 bits on */
void Exactly3(int arr[], int size)
{	
	int i = 0;
	
	for(i = 0; i < size; i++)
	{
		if(3 == CountBits(arr[i]))
		{
			printf("in the num %d there is exactly 3 bit on\n", arr[i]);
		}
	}
}


/* resived char, and return the mirror of the char */
char Mirror (char num)
{
	char res = 0;
	int i = 0;
	
	for(i = 0; i < 7; i++)
	{ 
		if ((1 << i) & num)
		{
			res++;		
		}
		res <<=1;
	}
	
	return (res);
}


/* resived char, and return the mirror of the char */
char Mirror2 (char num)
{	
	char res = 0;
	char bit1;
	char bit2;
	
	/* swap between bits 0 and 7 */
	bit1 = num & 1;
	bit2 = num & 128;
	bit1 <<= 7;
	bit2 >>= 7;
	res |= bit1;
	res |= bit2;
	
	/* swap between bits 1 and 6 */
	bit1 = num & 2;
	bit2 = num & 64;
	bit1 <<= 5;
	bit2 >>= 5;
	res |= bit1;
	res |= bit2;
	
	/* swap between bits 2 and 5 */	
	bit1 = num & 4;
	bit2 = num & 32;
	bit1 <<= 3;
	bit2 >>= 3;
	res |= bit1;
	res |= bit2;

	/* swap between bits 3 and 4 */	
	bit1 = num & 8;
	bit2 = num & 16;
	bit1 <<= 1;
	bit2 >>= 1;
	res |= bit1;
	res |= bit2;
	
	return (res);
}


void PrintBitsOfChar(char num)
{
	int i = 0;
	
	for(i = 7; i >= 0; i--)
	{
		printf ("%c", ((1 << i) & num) ? '1' : '0');
	}
	printf("\n");
}


void PrintBitsOfInt(int num)
{
	int i = 0;
	
	for(i = 31; i >= 0; i--)
	{
		printf ("%c", ((1 << i) & num) ? '1' : '0');
	}
	printf("\n");
}


void PrintBitsOfFloat(float num)
{
	int *fptr = (int *)& num;
	int newNum = *fptr;
	PrintBitsOfInt(newNum);
}


int main(int argc, char *argv[])
{    
	int x = 5;
	int y = 3;
	int arr3[8] = {7,15,22,111,24,164,666,68};

	printf("\n");
	printf("\n");
	printf("Pow2(4, -3) = %f\n", Pow2(4, -3));
	
	printf("\n");
	printf("PowOfTwo(4) = %d\n", PowOfTwo(4));
	printf("PowOfTwo(17) = %d\n", PowOfTwo(17));
	printf("PowOfTwo(25) = %d\n", PowOfTwo(25));
	
	printf("\n");
	printf("PowOfTwo2(64) = %d\n", PowOfTwo2(64));
	printf("PowOfTwo2(17) = %d\n", PowOfTwo2(17));
	printf("PowOfTwo2(100) = %d\n", PowOfTwo2(100));
	
	printf("\n");
	printf("AddOne 15 %d\n", AddOne(15));
	printf("AddOne 17 %d\n", AddOne(17));
	printf("AddOne 19 %d\n", AddOne(19));
	printf("AddOne 33 %d\n", AddOne(33));
	
	printf("\n");
	printf("Closets 170 = %d\n", Closets(170));
	
	printf("\n");	
	printf("swap\n");	
	printf("x = %d y = %d\n", x, y);
	Swap(&x, &y);
	printf("x = %d y = %d\n", x, y);

	printf("\n");	
	printf("CountBits 127 = %d\n", CountBits(127));
	printf("CountBits 256 = %d\n", CountBits(256));
	printf("CountBits 400 = %d\n", CountBits(400));

	printf("\n");	
	printf("BitsTwoAndSixOn 127 = %d\n", BitsTwoAndSixOn(127));
	printf("BitsTwoAndSixOn 53 = %d\n", BitsTwoAndSixOn(53));
	printf("BitsTwoAndSixOn 10 = %d\n", BitsTwoAndSixOn(10));

	printf("\n");		
	printf("BitsTwoOrSixOn 2 = %d\n", BitsTwoOrSixOn(2));
	printf("BitsTwoOrSixOn 34= %d\n", BitsTwoOrSixOn(34));
	printf("BitsTwoOrSixOn 128 = %d\n", BitsTwoOrSixOn(128));
	
	printf("\n");		
	printf("SwapBitThreeAndFive 36 = %d\n", SwapBitThreeAndFive(36));

	printf("\n");		
	Exactly3(arr3, 8);
	
	printf("\n");
	printf("beffor mirror: ");		
	PrintBitsOfChar(51);
	printf("after mirror: ");		
	PrintBitsOfChar(Mirror(51));
	
	printf("\n");
	printf("beffor mirror2: ");		
	PrintBitsOfChar(100);
	printf("after mirror2:  ");		
	PrintBitsOfChar(Mirror2(100));
	
	printf("\n");
	printf("PowOfTwo2 1 = %d\n", PowOfTwo2(1));
	printf("PowOfTwo2 25 = %d\n", PowOfTwo2(25));
	printf("PowOfTwo2 64 = %d\n", PowOfTwo2(64));
	
	printf("\n");	
	PrintBitsOfChar(36);
	PrintBitsOfChar(SwapBitThreeAndFive(36));

	printf("\n");	
	printf("PrintBitsOfFloat 78.25: ");
	PrintBitsOfFloat(78.25);

	
	return (0);	
}






