#include <stdio.h>
#include <time.h>

int main () {
	
   time_t curtime;
   time(&curtime);
   printf("Current time = %s", ctime(&curtime));

   return(0);
}


/*


void *Memset(void *str, int c, size_t n)
{
	char word[8] = {c,c,c,c,c,c,c,c};
		
	char *res = str;
	int i = 0;
	int index = 0;
	int charInFirst = (8 - (((long) str) % 8 )) % 8;
	int numOfWords = (n - charInFirst) / 8;
	int charInEnd = n - charInFirst - (numOfWords * 8);

	printf("charInFirst = %d\n", charInFirst );
	printf("numOfWords = %d\n", numOfWords );
	printf("charInEnd = %d\n", charInEnd );
	
	printf ("%s\n", (char *)str);
	printf("address: %p\n", &res);
	
	/* copy the first chars */
	for(i = 0; i < charInFirst; i++)
	{
		*(char *)(res)  = c;
		res+=8;
		printf("1\n");
	}
	
	printf ("%s\n", (char *)str);
	printf("address: %p\n", &res);
	
	/* copy the words as possible */ 
	for(i = 0; i < numOfWords; i++)
	{
		*(unsigned long *)res = *(unsigned long *)word;
		printf("2\n");
		++res;
	}
	
	printf ("%s\n", (char *)str);
	printf("address: %p\n", &res);

	/* copy the last chars */
	for(i = 0; i < charInEnd; i++)
	{	
		*(char *)(res)  = c;
		printf("3\n");		
		++res;
	}
	printf ("%s\n", (char *)res);

	return(res);
}

*/