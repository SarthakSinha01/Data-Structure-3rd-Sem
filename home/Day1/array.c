/*
 *
 *
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n;					// declaring n to store the no. of elements in array.

	printf("Enter the number of elemets");
	scanf("%d", &n);

	int array[n];

	int i;

	srand(time(NULL));                   	// seeding random function with time.

	for(i = 0; i < n; i++)
		array[i] = rand() % 100;	// generating random numbers between 0 and 99.

	printf("The array is \n");
	for(i = 0; i < n; i++)
		printf("%d  ", array[i]);	// printing generated array.

	printf("\n");

	for(i = 0; i < n/2; i++)		// running algo only upto the mid of array to reverse it.
	{
 		array[i] = array[i] + array[n - i - 1];		// swapping i th number with (n-1) th number upto middle to reverse.
		array[n - i - 1] = array[i] - array[n - i - 1];	
		array[i] = array[i] - array[n - i - 1];
	}


	printf("Array after reversing\n");
	for(i = 0; i < n; i++)
		printf("%d  ", array[i]);		// printing reveersed array.
	
	printf("\n");

	return 0;
}	
