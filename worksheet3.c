#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/***************************************************
resived char ** and print it
***************************************************/
void PrintStr(char **str)
{
	int i = 0;
	for (i = 0; *(str+i); i++)
		{
			printf("%s\n",*(str+i));
		}
	printf("\n");
}


/***************************************************
resived char ** and copy it to another char **
***************************************************/
char **CopyToBuffer(char **str)
{
	int i = 0;
	int str_len = 0;
	char **buffer = NULL;

	/* count the length of envp */
	for (str_len = 0; *(str + str_len); str_len++);
	
	/* allocation memory to buffer */
	buffer = (char**) malloc (sizeof(char *) * (str_len + 1));
	
	if (!buffer)
	{
		return (NULL);
	}
	
	/* For each cell in str arr, a pointer buffer point to a new a array  */
	for (i = 0; i < str_len; i++)
	{
		int j = 0;
		int len = strlen(*(str + i)) + 1;

		/* allocation memory to sub buffer */
		*(buffer + i) = malloc (sizeof(char) * (len + 1));
		
		if(!(*buffer))
		{
			return (NULL);
		}
		
		/* copy the buffer to a sub buffer */
		for(j = 0; j < len; j++)
		{
			buffer[i][j] = tolower(str[i][j]);
		}	
		
		buffer[i][j] = '\0';	
	}
	
	/* initialize the last place to NULL */
	buffer[i] = NULL;
	
	return (buffer);
}


/***************************************************
As the function name implies, recived char **
and free memory and sub-memory
***************************************************/
void FreeBuffer(char **buffer)
{
	int i = 0;
	
	while (buffer[i] != NULL )
	{
		free(buffer[i]);
		buffer[i] = NULL;
		i++;
	}
	
	free (buffer);
	buffer = NULL;
}



int main(int argc, char* argv[], char** envp)
{
	char **buffer = CopyToBuffer(envp);
	
	PrintStr(envp);
	PrintStr(buffer);
	FreeBuffer(buffer);	

	return (0);
}
