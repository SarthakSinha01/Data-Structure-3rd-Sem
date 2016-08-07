#include<stdio.h>
#include<stdlib.h>

void check_diagonal(int **matrix, int n);
void check_identity(int **matrix, int n);

int main()
{
	int n;
	
	printf("Enter the order of the matrix");
	scanf("%d", &n);

	int i, j, **matrix;

	matrix = (int **) malloc(n * sizeof(int *));

	for(i = 0; i < n; i++)
		matrix[i] = (int *) malloc(n * sizeof(int));


	printf("Enter the matrix\n");
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("element(%d, %d) : ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	check_diagonal(matrix, n);
	check_identity(matrix, n);

	free(matrix);

	return 0;
}

void check_diagonal(int **matrix, int n)
{
	int i, j;
	int flag = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j)
			{
				if(matrix[i][j] == 0)
				{
					flag = 1;
					break;
				}
			}

			else
			{
				if(matrix[i][j] != 0)
				{
					flag = 1;
					break;
				}
			}
		}
	}

	if(flag)
		printf("Not a diagonal matrix.\n");

	else
		printf("Diagonal matrix.\n");

}


void check_identity(int **matrix, int n)
{
        int i, j;
        int flag = 0;

        for(i = 0; i < n; i++)
        {
                for(j = 0; j < n; j++)
                {
                        if(i == j)
                        {
                                if(matrix[i][j] != 1)
                                {
                                        flag = 1;
                                        break;
                                }
                        }

                        else
                        {
                                if(matrix[i][j] != 0)
                                {
                                        flag = 1;
                                        break;
                                }
                        }
                }
        }

        if(flag)
                printf("Not an identity matrix.\n");

        else
		printf("Identity matrix.\n");
}
 
