#include <stdio.h> /* for printf */
#include <string.h> /* for strlen */

void StrPlusStr(const char *str1, const char *str2, char *result)
{
	unsigned int str_len1 = strlen(str1);
	unsigned int str_len2 = strlen(str2);
	unsigned int result_len = (str_len1 > str_len2) ? str_len1 : str_len2;
	int num1 = 0;
	int num2 = 0;
	int remainder = 0;
	int tmp = 0;
	int i = 0; 
	
	while(i < str_len1 && i < str_len2)
	{ 
		num1 = str1[str_len1 - i - 1] - '0';
		num2 = str2[str_len2 - i - 1] - '0';
		tmp = ((num1 + num2) % 10) + remainder;
		remainder = (num1 + num2) / 10;
		result[i] = (tmp + '0');
		++i;
	}

	while(i < str_len2)
	{ 
		num2 = str2[str_len2 - i - 1] - '0';
		tmp = (num2 + remainder) % 10;
		remainder = (num2 + remainder) / 10;
		result[i] = (tmp + '0') ;
		++i;
	}

	while(i < str_len1)
	{ 
		num1 = str1[str_len1 - i - 1] - '0';
		tmp = (num1 + remainder) % 10;
		remainder = (num1 + remainder) / 10;
		result[i] = (tmp + '0');
		++i;
	}
	
	if(remainder > 0)
	{
		result[i] = remainder + '0' ;
		++result_len;
	}
	
	result[result_len] = '\0';
	
	/* reverse */
	for(i = 0; i < result_len / 2; i++)
	{
		char tmp = result[i];
		result[i] = result[result_len - 1 - i];
		result[result_len - 1 - i] = tmp;
	}
}


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
		if ((strchr(delimiter_arr, str[read]) != NULL) &&
					 (NULL == strchr(delimiter_arr, str[read + 1])))
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
	char *str1 = "9999";
	char *str2 = "1";
	char str3[10];
	
	char str[100] = "123This123is123www2tutorial231point223website13212";
	char delimited_arr[] = {"1234"};

	/* StrPlusStr */	
	printf ("\nStrPlusStr\n");
	StrPlusStr(str1, str2, str3);
	printf("%s + %s = %s\n",str1, str2, str3);

	str1 = "1234";
	str2 = "2345";
	StrPlusStr(str1, str2, str3);
	printf("%s + %s = %s\n",str1, str2, str3);
	
	str1 = "25000";
	str2 = "2000";
	StrPlusStr(str1, str2, str3);
	printf("%s + %s = %s\n",str1, str2, str3);
	
	/* ReplaceDelimiter */
	printf ("\nReplaceDelimiter\n");
	printf ("%s\n", str);
	ReplaceDelimiter(str, delimited_arr, ' ');
	printf ("%s\n", str);

	
	return (0);
}

