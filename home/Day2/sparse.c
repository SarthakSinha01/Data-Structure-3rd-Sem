
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int row;
	int col;
	float data;
}element;

element *create_matrix(int size);
void input_matrix(element *matrix, int row, int col, int size);
element *add_matrix(element *matrix1, element *matrix2, int s1, int s2, int *s3);


int main()
{
	int r1, r2, c1, c2, n1, n2, n3, i;
	element *matrix1, *matrix2, *sum;

	printf("Enter the rows, cols and no. of elements of first matrix : ");
	scanf("%d %d %d", &r1, &c1, &n1);

	printf("Enter the rows, cols and no. of elements of second matrix : ");
	scanf("%d %d %d", &r2, &c2, &n2);

	matrix1 = create_matrix(n1);
	matrix2 = create_matrix(n2);

	printf("Enter the first matrix\n");
	input_matrix(matrix1, r1, c1, n1);

	printf("Enter the second matrix\n");
	input_matrix(matrix2, r2, c2, n2);


	sum = add_matrix(matrix1, matrix2, n1, n2, &n3);

	printf("SUM:\n");

	printf("Row\tCol\tData\n");
	printf("%d\t%d\t%.0f\n", sum[0].row, sum[0].col, sum[0]. data);
	for(i = 1; i <= n3; i++)
	{
		printf("%d\t%d\t%.2f\n", sum[i].row, sum[i].col, sum[i].data);
	}


	return 0;
}	


element *create_matrix(int size)
{
	element *matrix;
	matrix = (element *)malloc((size+1) * sizeof(element));
	return matrix;
}


void input_matrix(element *matrix, int row, int col, int size)
{
	matrix[0].row = row;
	matrix[0].col = col;
	matrix[0].data = (float)size;

	int i;

	for(i = 0; i < size; i++)
	{
		printf("Enter the row, col, data for the %dth element : ", i+1);
		scanf("%d %d %f", &matrix[i+1].row, &matrix[i+1].col, &matrix[i+1].data);
	}
}

element *add_matrix(element *matrix1, element *matrix2, int s1, int s2, int *s3)
{
	int i, j, b, s, n;
	element *big, *small, *sum;

	if(s1 > s2)
	{
		b = s1;
		s = s2;
		big = matrix1;
		small = matrix2;
	}

	else
	{
		b = s2;
		s = s1;
		big = matrix2;
		small = matrix1;
	}

	sum = create_matrix(b);

	for(i = 0; i <= b; i++)
	{
		sum[i] = big[i];
	}

	n = b;
	int flag;

	for(i = 0; i < s; i++)
	{
		flag = 0;
		for(j = 0; j < b; j++)
		{
			if(sum[j+1].row == small[i+1].row && sum[j+1].col == small[i+1].col)
			{
				sum[j+1].data = sum[j+1].data + small[i+1].data;
				flag = 1;
				break;
			}

		}

		if(!flag)
		{
			n++;
			sum = realloc(sum , (n+1)*sizeof(element));
			sum[n] = small[i+1];
		}
	}

	sum[0].data = (float)n;
	*s3 = n;
	return sum;
}
