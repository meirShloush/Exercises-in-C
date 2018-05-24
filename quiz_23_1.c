#include <stdio.h>
#include <string.h>
#include "Stack"

char *Chack(const char *arr)
{
	int i = 0;
	int size = strlen(arr);
	
	Stack *stack = StackCreat(1, size);
	
	for (i = 0; i < size; i++)
	{
		if ('('(arr[i]) || '['(arr[i]) || '{'(arr[i]))
		{
			StackPush(stack, )
		}
		else if (')'(arr[i]) || ']'(arr[i]) || '}'(arr[i]))
		{
			char c;
			if (IsEmpty(stack))
			{
				return (arr + i);
			}
			c = *(char *)StackPeek(StackPeek);
			if (((')' == (arr[i]) && ('(' == c)) || 
				((']' == (arr[i]) && ('[' == c)) ||
				(('}' == (arr[i]) && ('{' == c)) != 1 )
			{
				return (arr + i);
			}

			StackPop(StackPeek);
		}
	}

	if ((IsEmpty(stack)) != 1)
	{
		return (arr + i);
	}

	return (NULL);
}

int main()
{

	return (0);
}








