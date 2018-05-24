#include <stdio.h>


int IntEqual(void *a, void *b, void *c)
{
	return ((*(int *)a + *(int *)b) - *(int *)c);
}

int FloatEqual(void *a, void *b, void *c)
{
	return (!!((*(float *)a + *(float *)b) - *(float *)c));
}

void NumEqualTo2Element(const void *arr, size_t len, size_t element_size,
						void *num,
						int (* fp)(void *, void *, void *), 
						int res[])
{	
	void *first = (void *)((size_t)arr);
	void *end = (void *)((size_t)arr + (element_size * (len - 1)));
	
	res[0] = -1;
	res[1] = -1;
	
	while (fp(first, end, num) >= 0 && first < end)
	{
		end = (void *)((size_t)end - element_size);
	}
	
	while (first < end)
	{		
		if (fp(first, end, num) < 0)
		{
			first = (void *)((size_t)first + element_size);
		}
		else if (0 == fp(first, end, num))
		{
			res[0] = ((size_t)first - (size_t)arr) / element_size;
			res[1] = ((size_t)end - (size_t)arr) / element_size;
			
			return;
		}
		else
		{
			end = (void *)((size_t)end - element_size);
		}
	}
}

int main()
{
	int arr[] = {-8,-4,1,3,5,6,7,8,11,12,15,18,25, 40, 50};
	int num = 30;
	int res[2];

	NumEqualTo2Element(arr, 15, 4, &num, IntEqual, res);
	
	printf("i = %d, j = %d \n", res[0], res[1]);
	
	
	/*
	NumEqualTo2NumInArr(arr, 11, 50, res);
	printf("i = %d, j = %d \n", res[0], res[1]);
	*/
	
		
	return (0);
}



