#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n;

	printf("Enter the number of elemets");
	scanf("%d", &n);

	int array[n];

	int i;

	srand(time(NULL));

	for(i = 0; i < n; i++)
		array[i] = rand() % 100;

	printf("The array is \n");
	for(i = 0; i < n; i++)
		printf("%d  ", array[i]);

	printf("\n");

	for(i = 0; i < n/2; i++)
	{
 		array[i] = array[i] + array[n - i - 1];
		array[n - i - 1] = array[i] - array[n - i - 1];
		array[i] = array[i] - array[n - i - 1];
	}


	printf("Array after reversing\n");
	for(i = 0; i < n; i++)
		printf("%d  ", array[i]);
	
	printf("\n");

	return 0;
}	
