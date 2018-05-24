#include <stdio.h>
#include <string.h>
#include <assert.h>

static void Swap(char *arr, size_t from, size_t to)
{
	char tmp = arr[from];
	arr[from] = arr[to];
	arr[to] = tmp;
}

void Reverse(char *arr, size_t from, size_t to)
{
	assert(from < to);
	assert(to < strlen(arr));
	
	while(from < to)
	{
		Swap(arr, from, to);
		++from;
		--to;
	}
}

void ReverseWord(char *arr)
{
	int from =0;
	int to = 0;

	Reverse(arr, 0, (strlen(arr) - 1));
	
	while (arr[to] != '\0')
	{
		++to;
		if (arr[to] == ' ')	
		{
			Reverse(arr, from, to - 1);
			++to;
			from = to;
		}
	}
	
	Reverse(arr, from, to - 1);
}

int main()
{
	char arr[] = "You can define the typedef and forward declare the struct first in";

	printf("%s \n", arr);
	
	ReverseWord(arr);
	
	printf("%s \n", arr);

	return (0);
}
