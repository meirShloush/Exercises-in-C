#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main()
{
	int r_strcmp;
	int r_strlen;
	int tmp1;
	int tmp2;
	
	
	char *str1 = "mmm mmm mmm  nnn ";	
	char *str2;	
	char *str3;
	char *str4;
	char *str5;
	

	
	char strtok[] = "meir.shloush.aaa.bbb\0";
	const char strdelim[2] = ".";
	char *token;
	
	
	
	/* Strcat */
	char str13[50] = "destination";
	char *p_str13 = str13;
	const char str14[] = "source\n";
 	const char *p_str14 = str14;
	char *dest1314;
 	 	 
 	/* Strncat */
 	char str15[50] = "destination";
	char *p_str15 = str15;
	const char str16[] = "source\n";
 	const char *p_str16 = str16;
 	char *dest1516;
 	
 	

    /* Strlen */
    printf("\nStrlen\n"); 
    str1 = "meir shloush";
	r_strlen = Strlen(str1);
	printf("size of %s = %i\n", str1, r_strlen);


    /* Strcmp */
    printf("\nStrcmp\n"); 
    str2 = "meirg";	
	str3 = "meirb";
	r_strcmp = Strcmp(str2, str3);
	printf("%s and %s = %i\n", str2, str3, r_strcmp); 
	


	/* Strcpy */
	printf("\nStrcpy\n"); 
	str1 = "meir shloush";
	str4 = malloc(20 * sizeof(char));
	Strcpy (str4, str1);
    printf("%s\n", str4);
    free(str4);


	/* Strncpy */
	printf("\nStrncpy\n"); 
	str5 = malloc(20 * sizeof(char));
 	Strncpy(str5, "meir shloush ", 7);
    printf("%s\n", str5);
    free(str4);
    
    /* Strcasecmp */
    printf("\nStrcasecmp\n"); 
    str1 = "mEiR";
    str2 = "meir";
    tmp1 = Strcasecmp(str1, str2);
	printf("%s and %s = %i\n", str1, str2, tmp1);
	
	str1 = "mEiR";
    str2 = "meirs";
    tmp1 = Strcasecmp(str1, str2);
	printf("%s and %s = %i\n", str1, str2, tmp1); 
   
    /* Strchr */
    printf("\nStrchr\n");
    str1 = "This is a copy"; 
    printf("%p\n", Strchr(str1, 'l'));   
    printf("%p\n", Strchr(str1, 'i')); 
   
   /* Strdup */   
   printf("\nStrdup\n"); 
   str1 = "this is strdup";
   str2 = Strdup(str1);
   printf("%s\n", str2); 
    
   /* Strcat */
    printf("\nStrcat\n"); 
	dest1314 = Strcat(p_str13, p_str14);
	printf("%s\n", dest1314);

	/* Strncat */
	printf("\nStrncat\n"); 
	dest1516 = Strncat(p_str15, p_str16, 4);
	printf("%s\n", dest1516);

	
	
	/* Strstr */
	printf("\nStrstr\n"); 
	str1 = Strstr("abcdefgh","cdd");	
	if(str1)
	{
		printf("%s\n", str1); 
	}
	else 	
	{
		printf("not exist \n"); 
	}

	str1 = Strstr("abcdefgh", "cde");	
	if(str1)
	{
		printf("%s\n", str1); 
	}
	else 	
	{
		printf("not exist \n"); 
	}


	

	/* Strspn */
	printf("\nStrspn\n"); 
    tmp1 = Strspn("ABE", "AEBCDEF1G0B");
    tmp2 = strspn("ABE", "AEBCDEF1G0B");
	 printf("S %i, s %i\n", tmp1, tmp2);

 	 tmp1 = Strspn ("129th","123456t7890");
	 tmp2 = strspn ("129th","123456t7890");
	 printf("S %i, s %i\n", tmp1, tmp2);
	
	 tmp1 = Strspn ("m129th","1234567890");
	 tmp2 = strspn ("m129th","1234567890");
	 printf("S %i, s %i\n", tmp1, tmp2);
	
	
	/* Strtok */
	
	

	
	printf( "%s\n", strtok );
   
	token = Strtok(strtok, strdelim);

	while( token != NULL )
	{
	    printf( "%s\n", token );
		token = Strtok(NULL, strdelim);
   }
	
	

	
	
	
	return (0);
}


/******************************************************
Computes the length of the string str up to but not 
including the terminating null character.
*******************************************************/
int Strlen(const char *str)
{
	int counter = 0;
	int i = 0;
	
	while (*(str +i) != '\0')
	{
		counter++;
		i++;
	}
	
	return (counter);
}

/******************************************************
Compares the string pointed to, by str1 to the string 
pointed to by str2.
*******************************************************/
int Strcmp(const char *str1, const char *str2)
{
	while(*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++; 
	}
	
	return (*str1 - *str2);
}



/******************************************************
Copies the string pointed to, by src to dest.
*******************************************************/
char *Strcpy(char *dest, const char *src)
{
	int i = 0;
	int src_size = Strlen(src);
	char *res = dest; 
	
	/*for every i copy from src to dest */
	for(i = 0; i < src_size; i++)
	{
		*(dest + i) = *(src + i);
	}
	
	return (res);
}


/******************************************************
Copies up to n characters from the string pointed to, 
by src to dest.
*******************************************************/
char *Strncpy(char *dest, const char *src, size_t n)
{
	int i = 0;
	char *res = dest;
	
	if(n > Strlen(src))
	{
		n = Strlen(src);
	}
	
	/*for every i copy from src to dest */
	for(i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	
	return (res);
}

/******************************************************
Compare S1 and S2, ignoring case, returning less than, 
equal to or greater than zero if S1 is lexicographically 
less than, equal to or greater than S2.
*******************************************************/
int Strcasecmp(const char *str1, const char *str2)
{
	while(tolower(*str1) == tolower(*str2) && *str1 && *str2)
	{
		str1++;
		str2++; 
	}
	return (tolower(*str1) - tolower(*str2));
}


/******************************************************
Searches for the first occurrence of the character c (an 
unsigned char) in the string pointed to, by the argument str.
*******************************************************/
char *Strchr(const char *str, int c)
{
	int i = 0;
	
	/* while we have not reached the end of the str */
	while(*(str + i))
	{
	   if(*(str + i) == (char)(c))
		{
			return (char*)(str + i);
		}
		i++;
	}
	return ('\0');
}


/******************************************************
returns a pointer to a new string which is a duplicate 
of the string src. 
*******************************************************/
char *Strdup(const char *src)
{
	int i = 0;
	int size = Strlen(src);
	/* allocate memory for a dest */
	char* dest = malloc((size+1) * sizeof(char));
	
	if(dest == NULL)
	{
		return(NULL);
	}
	
	while(i < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	
	 *(dest + size + 1) = '\0';
	return(dest);
}

/******************************************************
Appends the string pointed to, by src to
the end of the string pointed to by dest.
*******************************************************/


char *Strcat(char *dest, const char *src)
{
	int dest_size = Strlen(dest);
	int i = 0;
	
	/* Start copping */
	while (*(src + i))
	{
		*(dest + dest_size + i) = *(src + i);
		i++;
	}
	
	*(dest + dest_size + i) = '\0';
	
	return (dest);
}


/******************************************************
Appends the string pointed to, by src to the end of 
the string pointed to, by dest up to n characters long.
*******************************************************/

char *Strncat(char *dest, const char *src, size_t n)
{
	int dest_size = Strlen(dest);
	int src_size = Strlen(src);
	int i = 0;
	
	if(n > src_size)
	{
		n = src_size;
	}
	
	/* copping */ 
	while (i < n)
	{
		*(dest + dest_size + i) = *(src + i);
		i++;
	}
	
	*(dest + dest_size + i) = '\0';
	
	return (dest);
}


/******************************************************
Finds the first occurrence of the entire string needle 
(not including the terminating null character) 
which appears in the string haystack.
*******************************************************/
char *Strstr(const char *haystack, const char *needle)
{
	int i = 0;
	int k = 0;
	
	while(*(haystack + i) != '\0')
	{
		while(*(haystack + i + k) == *(needle + k))
		{			
			if(*(needle + k + 1) == '\0')  
			{
				return (char *) (haystack + i ); 
			}
			k++;
		}
		i++;
		k = 0;
	}
	
	return(NULL);
}

/******************************************************
Calculates the length of the initial segment of str1 
which consists entirely of characters in str2.
*******************************************************/
size_t Strspn(const char *str1, const char *str2)
{
	int count = 0;
	int flag = 0;
	int str1_size = Strlen(str1);
	int str2_size = Strlen(str2);
	int i, j;

	for(i = 0; i < str1_size; i++)
	{
		for(j = 0; j < str2_size; j++)
		{
			if(*(str1 + i) == *(str2 + j))
			{
				count ++;
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			return (count);
		}
		flag = 0;
	}
	
	return (count);
}


char *Strtok(char *str, const char *delim)
{
	static char *res;
	static int num;
	int i = 0;

	if(str != NULL)
	{
		res = str;
		for (i = 0; i < Strlen(str); i++)
		{
			if(*(str + i) == *delim)
			{
				num++;
			}
		}
		num++;
	}
	
	str = res;
	
	if(0 == num)
	{
		return (NULL);
	}
	while (*res != *delim)
	{
		res++;
	}
	
	*(res) = '\0';
	res++;
	num--;
	return (str);
}






