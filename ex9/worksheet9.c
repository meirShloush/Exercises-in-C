#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WORD 8

void *Memset(void *str, int c, size_t n);
void *Memcpy(void *dest, const void *src, size_t n);
void *Memmove(void *dest, const void *src, size_t n);
char *Itoa ( int value, char * str, int base );
int Atoi(const char *str);


int main(int argc, char **argv)
{
	char str[50];
	char strSrc[100];
	char strDest[100];
	int num = 0;
    char buffer[20];

	
	printf("\n------Memset-------\n");
	strcpy(str,"This is string.h library function");
	printf("%s\n", str);
	Memset(str + 2,'$', 21);
	printf("%s\n", str);
	
		
	printf("\n------Memcpy-------\n");
	strcpy(strSrc, "This is string.h library function");
	printf("Memcpy: %s\n", (char *)Memcpy(strDest, strSrc, 17));

	strcpy(strSrc, "This is string.h library function");
	printf("memcpy: %s\n", (char *)memcpy(strDest, strSrc, 17));


    printf("\n------Memmove-------\n");
	strcpy(strSrc, "This is string.h library function");
	printf("Memmove: %s\n", (char *)Memmove(strDest, strSrc, 4));
	
	strcpy(strSrc, "This is string.h library function");
	printf("memmove: %s\n", (char *)memmove(strDest, strSrc, 4));
	
	
    printf("\n------Itoa-------\n");
	num = 1000;
    Itoa(num,buffer,2); 
    printf("Binary value = %s\n", buffer);
 
    Itoa(num,buffer,10); 
    printf("Decimal value = %s\n", buffer);
 
    Itoa(num,buffer,16); 
    printf("Hexadecimal value = %s\n", buffer);
	
	printf("\n------Atoi---1234----\n");
	num = Atoi("1234");
	printf("%d\n", num);
	
	return (0);
}

/* copies the character c, to the first n characters of str. */
void *Memset(void *str, int c, size_t n)
{
	void *res = str;
	int i = 0;
	int charsInFirst = (n >= WORD) ? ( (WORD - (((unsigned long) str) % WORD )) % WORD ) : n;
	int numOfWords = (n > WORD) ? ( (n - charsInFirst) / WORD ) : 0;
	int charsInEnd = (n > 0) ? ( n - charsInFirst - (numOfWords * WORD) ) : 0 ;
	
	char word[WORD];
	/* build chunck in size of word, for copy */
	for(i = 0; i < WORD; i++)
	{
		*(word +i) = c;
	}	
	
	/* copy the first chars */
	for(i = 0; i < charsInFirst; i++)
	{
		*((char *)str) = c;
		str = (void *)(((size_t)str) + 1);
	}

	
	/* copy words as possible */ 
	for(i = 0; i < numOfWords; i++)
	{
		*((unsigned long *) str)  = *(unsigned long *)word;  
		str = (void *)(((size_t)str) + WORD);
	}
		
	/* copy the last chars */
	for(i = 0; i < charsInEnd; i++)
	{	
		*((char *)str) = c;
		str = (void *)(((size_t)str) + 1);
	}

	return(res);
}


/* copies n characters from memory area src to memory area dest. */
void *Memcpy(void *dest, const void *src, size_t n)
{
	void *res = dest;
	int i = 0;
	int charsInFirst = (n >= WORD) ? ( (WORD - (((unsigned long) src) % WORD )) % WORD ) : n;
	int numOfWords = (n > WORD) ? ( (n - charsInFirst) / WORD ) : 0;
	int charsInEnd = (n > 0) ? ( n - charsInFirst - (numOfWords * WORD) ) : 0 ;
	
	/* copy the first chars */
	for(i = 0; i < charsInFirst; i++)
	{
		*((char *)dest) = *((char *)src);
		dest = (void *)(((size_t)dest) + 1);
		src = (void *)(((size_t)src) + 1);							
	}

	/* copy words as possible */ 
	for(i = 0; i < numOfWords; i++)
	{
		*((unsigned long *) dest)  = *((unsigned long *) src); 
		dest = (void *)(((size_t)dest) + WORD);
		src = (void *)(((size_t)src) + WORD);
	}
		
	/* copy the last chars */
	for(i = 0; i < charsInEnd; i++)
	{	
		*((char *)dest) = *((char *)src);
		dest = (void *)(((size_t)dest) + 1);
		src = (void *)(((size_t)src) + 1);
	}

	*((char *)dest) = '\0';
		
	return(res);
}


/* copies n characters from src to dest, but for overlapping memory blocks */
void *Memmove(void *dest, const void *src, size_t n)
{
	void *res = dest;

	if(dest == src )
	{
		return (res);
	}
		
	/* in case that there are overlap */
	if( ((size_t)dest > (size_t)src ) && ( ((size_t)dest - (size_t)src) < n ) )
	{	
		int i = 0;
		int numOfWords = n / WORD;
		int charsInEnd = n - (numOfWords * WORD) ;	

		/* offset addres of dest and src to the addres + n */
		dest = (void *)(((size_t)dest) + n);
		src = (void *)(((size_t)src) + n);
		
		/* copy the last chars */
		for(i = 0; i < charsInEnd; i++)
		{	
			dest = (void *)(((size_t)dest) - 1);
			src = (void *)(((size_t)src) - 1);
			*((char *)dest) = *((char *)src);
		}		
		
		/* copy words as possible */ 
		for(i = 0; i < numOfWords; i++)
		{
			dest = (void *)(((size_t)dest) - WORD);
			src = (void *)(((size_t)src) - WORD);
			*((unsigned long *) dest)  = *((unsigned long *) src); 			
		}	
	}
	
	else
	{
		res = Memcpy(dest, src, n);
	}
	
	return (res);
}


/* converts int data type to string data type for any base */
char *Itoa (int value, char* str, int base)
{
	int numOfDigits = 0;
	int tmp = value;
	
	for (numOfDigits = 0; tmp /= base; numOfDigits++);
	
	if (0 > value)
	{
		*str = '-' ;	
		numOfDigits++;
		value = -value;
	}
	
	*(str + numOfDigits + 1) = '\0';
	
	/* copy from value to str */
	while( 0 <= numOfDigits)
	{
		if( 9 >= (value % base) )
		{
			*(str + numOfDigits) = (char)((value % base) + '0');
		}
		/* for hex num */
		else 
		{
			*(str + numOfDigits) = (char)((value % base) + 'A' - 10);
		}
		
		value /= base;
		numOfDigits--;
	}
	
	return(str);
}  


/* converts the string argument str to an integer */
int Atoi(const char *str)
{
	int i = 0;
	int res = 0;
	int size = strlen(str);

	for (i = 0; i < size; i++)
	{
		res *= 10;
		res += (*(str + i) - '0');
	}
	
	return (res);
}


