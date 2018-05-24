#include <string.h>
#include <stdio.h>


int StrcmpFromIndex(char *str1, char *str2, int index)
{
	int i = 0;
	int size = strlen(str1);
	
	for(i = 0; i < size; i++)
	{
		if( *(str1 + i) != *(str2 + (index %= size)) )
		{
			return (0);
		}
		index ++;
	}
	
	return (1);
}


int ChackRotate(char *str1, char *str2)
{
	int i = 0;
	int size = strlen(str1);
	
	if(size != strlen(str2))
	{
		return (0);
	}
	
	for(i = 0; i < size; i++)
	{
		if( *str1 != *(str2 + i) )
		{
			continue;
		}
		
		if( StrcmpFromIndex (str1, str2, i) == 1 )
		{
			return (1);
		}
	}
	
	return (0);
}


int main()
{
	char *str1 = "11231";
	char *str2 = "12311";	
	int i = ChackRotate(str1, str2);
	
	printf(i ? "%s is rotatet of %s\n" : "%s is not rotatet of %s\n", str2, str1);
	
	return(0);
}



