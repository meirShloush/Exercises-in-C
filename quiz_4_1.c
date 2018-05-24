#include <stdio.h>
#include <string.h>

size_t MaxChar(size_t arr[])
{
	int i = 0;
	int res = 0;
	for(i = 0; i < 256; i++)
	{
		if(arr[i] > res)
		{
			res = arr[i];
		}
	}
	return (res);
}

void PrintMaxCharNum(char c)
{
	static size_t arr[256];

	if(c != '\0')
	{
		arr[(int)c]++;
	}
	else
	{
		printf("%d \n", (int)MaxChar(arr));
		memset(arr, 0, 256);
	}
}


int main(int argc, char **argv)
{
	int i = 0;
	char arr[10] = {1,2,1,2,3,4,1,1,3,4};
	
	for(i = 0; i < 10; i++)
	{
		PrintMaxCharNum(arr[i]);
	}

	PrintMaxCharNum('\0');	
	
	return (0);
}



