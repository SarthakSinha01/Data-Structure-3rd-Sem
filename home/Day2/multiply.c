
#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	int x;
	int y;
	float c;
}term;


term *create_polynomial(int size);
term *add_polynomial(term *p1, term *p2, int s1, int s2, int *n);
term *multiply_polynomial(term *p1, term *p2, int s1, int s2, int *n);

int main()
{
	int s1, s2, n, i;

	term *p1, *p2, *product;

	printf("Enter the number of terms of the first polynomial");
	scanf("%d", &s1);

	printf("Enter the number of terms in the second polynomial");
	scanf("%d", &s2);

	p1 = create_polynomial(s1);
	p2 = create_polynomial(s2);

	printf("Enter the first polynomial\n");
	for(i = 0; i < s1; i++)
	{
		printf("Enter the %dth term(co-efficient, power of x, power of y)", i+1);
		scanf("%f %d %d", &p1[i].c, &p1[i].x, &p1[i].y);
	}

	printf("Enter the second polynomial\n");
	for(i = 0; i < s2; i++)
	{
		printf("Enter the %dth term(co-effiecient, power of x, power of y)", i+1);
		scanf("%f %d %d", &p2[i].c, &p2[i].x, &p2[i].y);
	}

	product = multiply_polynomial(p1, p2, s1, s2, &n);


	printf("Product : \n");
	printf("%f(x^%d)(y^%d) ", product[0].c, product[0].x, product[0].y);

	for(i = 1; i < n; i++)
	{
		printf("+ %f(x^%d)(y(^%d)", product[i].c, product[i].x, product[i].y);
	}

	printf("\n");

	free(p1);
	free(p2);
	free(product);

	return 0;
}


term *create_polynomial(int size)
{
	term *p;

	p = (term *)malloc(size * sizeof(term));

	return p;
}


term *add_polynomial(term *p1, term *p2, int s1, int s2, int *n)
{
	int b, s, i, ns, flag, j;
	term *big, *small, *sum;

	if(s1 > s2)
	{
		b = s1;
		s = s2;
		big = p1;
		small = p2;
	}

	else
	{
		b = s2;
		s = s1;
		big = p2;
		small = p1;
	}


	sum = create_polynomial(b);

	ns = b;

	for(i = 0; i < b; i++)
	{
		sum[i] = big[i];
	}

	for(i = 0; i < s; i++)
	{
		flag = 0;
		for(j = 0; j < b; j++)
		{
			if(sum[j].x == small[i].x && sum[j].y == small[i].y)
			{
				sum[j].c = sum[j].c + small[i].c;
				flag = 1;
				break;
			}
		}

		if(!flag)
		{
			ns++;
			sum = realloc(sum, ns * sizeof(term));
			sum[ns - 1] = small[i];
		}
	}

	*n = ns;

	return sum;
}


term *multiply_polynomial(term *p1, term *p2, int s1, int s2, int *np)
{
	int b, s, i, n, flag, j;
        term *big, *small, *product, *multi;

        if(s1 > s2)
        {
                b = s1;
                s = s2;
                big = p1;
                small = p2;
        }

        else
        {
                b = s2;
                s = s1;
                big = p2;
                small = p1;
        }

	n = 0;
	product = NULL;

	multi = create_polynomial(s);

	for(i = 0; i < b; i++)
	{
		for(j = 0; j < s; j++)
		{
			multi[j].c = big[i].c * small[j].c;
			multi[j].x = big[i].x + small[j].x;
			multi[j].y = big[i].y + small[j].y;
		}

		product = add_polynomial(product, multi, n, s, &n);
	}

	free(multi);

	*np = n;

	return product;
}
