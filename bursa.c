#include <stdio.h>
#include <stdlib.h>

int *Bursa(int arr[], int len)
{
	int i = 0;
	int tmp = *arr;
	int *res = malloc(3 * sizeof(int));
	*res = 0;
	*(res + 1) = 1;
	*(res + 2) = *(res +1) - *res;
	
	for(i = 2; i < len; i++)
	{
		if(*(arr + i) > *(arr + (*(res + 1))))
		{
			*(res + 1) = i;
			*(res + 2) = *(arr + (*(res + 1))) - *(arr + (*res));
			continue;
		}
		
		if(arr[i] < tmp)
		{
			tmp = i;
			continue;
		}
		
		if( ( (*(arr + i) - *(arr + tmp) )> *(res + 2) ))
		{
			*res = tmp;
			*(res +1) = i;
			*(res + 2) = *(arr + i) - *(arr + tmp);
		}	
	}
	return(res);
}

int main(int argc, char *argv[])
{
	int arr[] = {6,12,3,5,1,4,9,2,25,60,80,12,1,100,23,44,17,200,120,130};
	int *res = Bursa(arr, 20);
	
	int i = 3;
	for(i = 0; i < 3; i++)
	{
		printf("%d ", *(res + i));
	}
	printf("\n");
	
	free(res);
	res = NULL;

	return (0);
}
