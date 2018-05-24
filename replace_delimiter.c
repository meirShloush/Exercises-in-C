#include <stdio.h>
#include <string.h>

void ReplaceDelimiter(char str[], char delimiter_arr[], char rep)
{
	int read = 0;
	int write = 0;
	int len = strlen(str);
	
	while (strchr(delimiter_arr, str[read]) != NULL && read < len)
	{
		read++;
	}
	
	while (read < len)
	{
		if ((strchr(delimiter_arr, str[read]) != NULL) && (NULL == strchr(delimiter_arr, str[read + 1])))
		{
			str[write] = rep;
			write++;
		}
		else if (NULL == strchr(delimiter_arr, str[read]))
		{
			str[write] = str[read];
			write++;
		}
		read++;
	}
	
	str[write] = '\0';
}

int main()
{
	
	char str[100] = "123This123is123www2tutorial231point223website13212";
	char delimited_arr[] = {"1234"};

	printf ("%s\n", str);
	ReplaceDelimiter(str, delimited_arr, ' ');
	printf ("%s\n", str);
	
	return (0);
}

