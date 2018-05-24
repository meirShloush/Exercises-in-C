#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int NextSoldier(int arr[], int len, int cur);
int TheLastSurvivor(int num, int first);

int main()
{
	int num = 0;
	int winner = 0;
	int sword = 0;
	
	printf("enter the num of soldiers: ");
	scanf("%d",&num);
	
	printf("enter the num of sildier thet hold the sword, from 0 to %d: ", num-1);
	scanf("%d",&sword);
	
	winner = TheLastSurvivor(num, sword) ;
	printf("%d\n", winner);
	
	return (0);
}

/**************************************************************
the function recives arr, length of arr, and current location, 
and return the num of soldier that alive, and -1 if don't have.
**************************************************************/
int NextSoldier(int *arr, int len, int cur)
{
	int counter = 0;
	++cur;
	
	/* 	for(cur %= len; 1 != *(arr + cur); ++cur) */
	while (1 != *(arr + (cur %= len)))
	{ 
		++cur;
		++counter;
		
		/* So we went through the whole array, and did't find soldier in life */
		if(counter > len)
		{
			return (-1);
		}	
	}
	
	return (cur);
}


/**************************************************************
the function recives number, and location of doldier that hold the sword, 
and return the num of last survivor
**************************************************************/
int TheLastSurvivor(int num, int first)
{
	int i = 0;
	int sword = first;
	
	/* Memory allocation */
	int *arr = (int *)(malloc(num * sizeof(int)));
	
	if(!arr)
	{
		return (-1);
	}

	/* initialize the arr that all soldier are alive */
	for(i = 0; i < num; ++i)
	{
		*(arr + i) = 1;
	}
	
	while(1)
	{
		/* find the next soldier who lives */
		int next = NextSoldier(arr, num, sword);
		
		/* if next == -1, we have a winner */
		if(-1 == next)
		{
			break;
		}
		
		/* kill the next soldier */
		*(arr + next) = 0;
		
		/* find the next soldier who lives */
		next = NextSoldier(arr, num, sword);
		
		/* if next == -1, we have a winner */
		if(-1 == next)
		{
			break;
		}
		
		/* bring the sword to the next soldier*/
		sword = next;	
	}
	
	free(arr);
	arr = NULL;
	
	return (sword);
}

