#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void addToInt(void *num, void **ptr);
void addToFloat(void *num, void **ptr);
void addToString(void *str, void **ptr);

void printInt(void *ptr);
void printFloat(void *ptr);
void printString(void *ptr);	

void FreeMemory(char *str);


typedef struct
{
	void *data;
	void (*add)(void *num, void **ptr);
	void (*print)(void *ptr);	
	void (*FreeMemory)(char *ptr);			
}dataFunc;


int main(int argc, char **argv)
{	
	/* variables for int function */
	int numInt = 0;
	void *pNumInt = &numInt;
	int num = 15;
	
	/* variables for float function */
	float numFloat = 0;
	void *pNumFloat = &numFloat;
	float f = 7.4;

	/* variables for string function */
	void *pstr = calloc(1 , sizeof(char));
	char a[6] = "maggy";
	char b[8] = "meir";
	void * pstr1 = &a;
	void * pstr2 = &b;

	
	dataFunc arrFunc[3] = {NULL};
	
	/* Define int members */
	arrFunc[0].data = pNumInt;
	arrFunc[0].add = addToInt;
	arrFunc[0].print = printInt;
	arrFunc[0].FreeMemory = FreeMemory;

	/* Define float members */
	arrFunc[1].data = pNumFloat;
	arrFunc[1].add = addToFloat;
	arrFunc[1].print = printFloat;
	arrFunc[1].FreeMemory = FreeMemory;

	/* Define string members */
	arrFunc[2].data = pstr;
	arrFunc[2].add = addToString;
	arrFunc[2].print = printString;
	arrFunc[2].FreeMemory = FreeMemory;
	
	/* Call to functions */
	arrFunc[0].add(&num, pNumInt);
	arrFunc[0].print(pNumInt);
	
	arrFunc[1].add(&f, pNumFloat);		
	arrFunc[1].print(pNumFloat);
	
	arrFunc[2].add(pstr1, &pstr);
	arrFunc[2].add(pstr2, &pstr);	
	arrFunc[2].print(pstr);
	arrFunc[2].FreeMemory(pstr); 
	
	
	return (0);
}



/* add function */
void addToInt(void *num, void **ptr)
{
	*(int *)ptr += *(int *)num;
}


void addToFloat(void *num, void **ptr)
{
	*(float *)ptr += *(float *)num;
}


void addToString(void *str, void **pptr)
{
	/* size of realloc */
	int size = strlen((char *)str) + strlen((char *)*pptr) + 2;
	void *tmp = realloc(*pptr, size * sizeof(char));	
	
	if(tmp == NULL)
	{
		free(tmp);
		tmp = NULL;
		printf("Assignment failed\n");
		exit(0);
	}

	/* copy */
	strcat(tmp, " "); 
	strcat(tmp, (char *)str);
	
	*pptr = tmp;
	tmp = NULL;
}


/* print function */
void printInt(void *ptr)
{
	printf("%d\n", *(int *)ptr);
}


void printFloat(void *ptr)
{
	printf("%f\n", *(float *)ptr);
}


void printString(void *pptr)
{
	printf("%s\n", (char *)pptr);

}


void FreeMemory(char *str)
{
	free(str);
	str = NULL;
}




