#include <stdio.h>


/*******************************************************************************
res[0] = first_index. 
res[1] = last_index.
*******************************************************************************/
void SubMax(const int arr[], int len, int res[])
{
	int first_index = 0;
	int last_index = 0;
	int sum = 0;
	int res_sum = -1; /* in case that in array have only negative numbers,
					 except for one number equal to zero */

	while (last_index < len)
	{
		sum +=arr[last_index];

		if (sum > res_sum)
		{
			res_sum = sum;
			res[0] = first_index;
			res[1] = last_index;
		}
		if (sum < 0)
		{
			sum = 0;
			first_index = last_index + 1;
		}

		last_index++;
	}
}


int main()
{
	int arr0[] = {-5, 3, 0, -4, -5, -3, -12, -9, -70, -150};
	int arr1[] = {-5, 3, -12, 4, 5, -3, 12, 9, 70, 150};
	int arr2[] = {5, 3, -12, 4, 5, -3, 12, 9, -70, 150};		
	int arr3[] = {-5, 3, -2, 4, 5, -3, 12, 9, 70, -150};		
	int arr4[] = {5, 3, -2, 4, 5, -3, 12, 9, 70, 150};	
	int arr5[] = {-5, -3, 0, -4, -5, -1, -12, -9, -70, -150};		

	int res[2];
	
	SubMax(arr0, 10, res);
	if ((1 == res[0]) && (1 == res[1]))
	{
		printf("0. good\n");
	}
	else
	{
		printf("0. Oh no\n");
	}

	SubMax(arr1, 10, res);
	if ((3 == res[0]) && (9 == res[1]))
	{
		printf("1. good\n");
	}
	else
	{
		printf("1. Oh no\n");
	}


	SubMax(arr2, 10, res);
	if ((9 == res[0]) && (9 == res[1]))
	{
		printf("2. good\n");
	}
	else
	{
		printf("2. Oh no\n");
	}

	SubMax(arr3, 10, res);
	if ((1 == res[0]) && (8 == res[1]))
	{
		printf("3. good\n");
	}
	else
	{
		printf("3. Oh no\n");
	}

	SubMax(arr4, 10, res);
	if ((0 == res[0]) && (9 == res[1]))
	{
		printf("4. good\n");
	}
	else
	{
		printf("4. Oh no\n");
	}
	res[0] = 0;	
	res[1] = 0;

	SubMax(arr5, 10, res);
	if ((2 == res[0]) && (2 == res[1]))
	{
		printf("5. good\n");
	}
	else
	{
		printf("5. Oh no\n");
	}

	return (0);
}



