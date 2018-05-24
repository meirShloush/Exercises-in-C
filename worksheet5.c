#include <stdio.h>
#include <stdlib.h> /* For exit() */
#include <string.h>
#include "worksheet5.h"


int main()
{    
	
	char path[70] = "/home/batman42/svn/meir.shloush/Proj/src/exercises/txt_files/"; 
    char filename[20] ;
    char full_path[90];
	char c;
    char *input = NULL;
	char *tmp = NULL;
	int size = 10;
	int status = 0;
	int i = 0;

	S arr[4] =
	{
		{"-remove", Remove, strcmp},
		{"-count", Count, strcmp},
		{"-exit", Exit, strcmp},
		{"<", AppendToBeggin, FirsrStrcmp}
	};
	
	printf("Enter the filename: ");
    fgets(filename, 20, stdin);
	
	strcpy(full_path, path);	
	strcat(full_path, filename);
	
	while((-99) != status)
	{
		printf("Enter the command or a string: ");
		i = 0;
		size = 10;
		c = getchar(); 
		
		input = (char*)malloc(size * sizeof(char));	
		if(NULL == input)
		{
			return(-1);
		}
		
		while('\n' != c)
		{
			if (i == (size-1))
			{
				size +=10;
				tmp = (char *)realloc(input, size);
				if(NULL == tmp)
				{
					free(input);
					input = NULL;
					return(-1);
				}
				input = tmp;
				tmp = NULL;
			}
			*(input + i) = c;
			i++;
			c = getchar(); 
		}
		*(input + i) = '\0';
		
		status = CheckIfCommand(arr, full_path, input);
		
		/* if status == -1, than the inpus is not a keyword */
		if (1 == status)
		{
			Append(full_path, input);
		}
		free(input);
		input = NULL;
	}
	if(0 > status)
	{
		status = PrintError(status);
	}
    return (0);  
}

int FirsrStrcmp(const char* str1, const char* str2)
{
	if(*str1 == *str2)
	{
		return(0);
	}
	return(1);
}

int PrintError(int error_num)
{	
	switch(error_num)
	{
		case(Cannot_copy_file):
		{
			printf("Cannot copy file\n");
			break;
		}
		case(Cannot_rename_file):
		{
			printf("Cannot rename file\n");
			break;
		}
		case(Cannot_close_file):
		{
			printf("Cannot close file\n");
			break;
		}
			case(Cannot_open_file):
		{
			printf("Cannot open file\n");
			break;
		}
	}
	return (-99);
}

/* recived input, and return 1 if isn't a command, else - the status of command */
int CheckIfCommand(S *arr, const char *full_path, char *input)
{
	int i = 0;
	int status = 1;
	
	for(i = 0; i < 4; i++)
	{
		if( (arr + i)-> comp (input, (arr + i)->name) == 0) 
		{
			status = (arr + i)->opera(full_path, input);
			return (status);
		}
	}

	return (status);
}


/* close the program */
int Exit(const char *path, char *input)
{
	return (-99);
}


/* remove the file */
int Remove(const char *path, char *input)
{
	int ret = remove(path);
	if(0 != ret)
	{
		ret = Cannot_remove_file;
	}
	return (ret);	
}


/* count the line of a file */
int Count(const char *path, char *aaa)
{
	int counter = 0; 
	int c ;
	
	/* open the file to read */
	FILE *fptr = fopen(path, "r");
	if (NULL == fptr)
	{
		return (Cannot_open_file);
	}
	
	c = fgetc(fptr);
	while(EOF != c)
	{
		if('\n' == c)
		{
			++counter;
		}
		c = fgetc(fptr);
	}
	
	fclose(fptr);
	printf("counter = %d\n",counter);
	return (0);
}


/* recived input and path of file, and append the input at the end of file */
int Append(const char *path, char *input)
{
	int res;
	
	/* open the file to add */
	FILE *fptr = fopen(path, "a");
	if (NULL == fptr)
	{
		return (Cannot_open_file);
	}
	
	/* add \n to get down a line */
	strcat(input, "\n");
	
	res = fputs(input, fptr);

	fclose(fptr);
	
	return (res);

}


/* recived input and path of file, and append the input at the beginning of file */
int AppendToBeggin(const char *src_file, char *input)
{
	int res;
	char c[20];
	char tmp_file[80];
	FILE *fptr_tmp;
	FILE *fptr_source;
   
	strcpy(tmp_file, src_file);
	strcat(tmp_file, "tmp");
   
   	/* Open tmp_file for writing  */
	fptr_tmp = fopen(tmp_file, "a");
	if (NULL == fptr_tmp)
    {
        printf("Cannot open file %s \n", tmp_file);
        return (Cannot_open_file);
    }
    
	/* copy the input to tmp_file */
	input++;
	fputs(input, fptr_tmp);
	fputs("\n", fptr_tmp);
	
    /* Open src_file for reading */
    fptr_source = fopen(src_file, "r");
	if (NULL == fptr_source)
    {
        printf("Cannot open file %s \n", src_file);
        return (Cannot_open_file);
    }
 
	/* copy from src_file to tmp_file */
	while(fgets(c, 20, fptr_source) !=NULL)
    {
		fputs (c, fptr_tmp);
    }
 
	/* close the files */
    fclose(fptr_tmp);
    fclose(fptr_source);
    
	/* remove the src_file, and rename the tmp file to name of src_file*/
	remove(src_file);
    res = rename(tmp_file, src_file);
	if(0 != res)
	{
 	   return (Cannot_rename_file);    
	}

    return (0);    
}


