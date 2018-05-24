#include <stdio.h>


int FoundNum(int arr[], int len, int num)
{
	int i = 0;
	
	for(i = 0; ((i < len) && (arr[i] == num)); i++);
	
	return (!!(len - i));
}
    
int main (int argc, char *argv[])
{   
    int arr[10] = {1,2,4,5,7,9,11,14,22,33};
	
	printf("%d\n", FoundNum(arr, 10, 12) );
    
    return (0);
}

