#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct
{
	int min;
	int max;
	int value;
} msa;

void printMsa(msa m)
{
	printf("min = %d\n", m.min);
	printf("max = %d\n", m.max);
	printf("value = %d\n", m.value);
}

msa maximum(int arr[], int length)
{
	msa res = {0,0,0};
	msa tmp = {0,0,0};
		
	int i;

	while(arr[i] < 0)
	{
		i++;
	}

	while(arr[i] > 0)
	{
		res.min = i;
		res.max = i;
		res.value = arr[i];	
		i++;
	}

	res.min = i;
	res.max = i;
	res.value = arr[i];
	
	tmp.min = i;
	tmp.max = i;
	tmp.value = arr[i];
	
	i++;
	
	while(i < length)
	{		
		if(tmp.value < 0)
		{
			tmp.min = i;
			tmp.max = i;
			tmp.value = arr[i];
		}
		
		res.value += arr[i];
		res.max = i;
		
		tmp.value += arr[i];
		tmp.max = i;

		if( (tmp.value >= res.value) && (res.min != tmp.min) )
		{
			res.min = tmp.min;
			res.max = tmp.max;
			res.value = tmp.value;
			
			tmp.value = 0;
			tmp.min = i;
			tmp.max = i;
		}
		++i;
	}
	
	return (res);
} 

int main(int argc, char **argv)
{
	int arr[] = {1,2,3,4,-20, 100 -5,-7,3,-8,12,12,2,-222,44,33,-10};
	msa m = maximum(arr, 17);
	
	printMsa(m);
	
	return (0);
}
