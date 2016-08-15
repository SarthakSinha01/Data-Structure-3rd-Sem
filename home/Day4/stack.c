#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
	int data[MAX];
	int top;
} stack;

void display(stack s)
{
	if(s.top == -1)
	{
		printf("\nStack Is EMPTY\n");
	}
	else
	{
		printf("\n");
		while(s.top!= -1)
		{
			printf("|%7d|\n", s.data[s.top]);
			printf(" -------\n");
			s.top--;
		}
	}
}

void push(stack *s, int n)
{
	if(s->top == MAX)
		printf("STACK id FULL\n");
	else
	{
		s->top++;
		s->data[s->top] = n;
	}
	display(*s);
}

void pop(stack *s)
{
	if(s->top == -1)
		printf("\nStack is Empty\n");
	else
	{
		s->top--;
		display(*s);
		printf("The Deleted Value: %d\n", s->data[s->top+1]);
	}
}

int main()
{
	stack s;
	s.top = -1;
	char op;
	int sh;
	int data;
	do {
		printf("Enter \n(1) Push \n(2) Pop\n(3) Display\n(4) Exit");
		scanf("%d", &sh);
		getchar();
		switch(sh)
		{
			case 1:
			printf("Enter the value to be inserted: ");
			scanf("%d", &data);
			getchar();
			push(&s, data);
			break;

			case 2:
			pop(&s);
			break;

			case 3:
			display(s);
			break;

                        case 4:
                        break;
                        
			default :
			printf("You have entered a Wrong Choice\n");
			break;
		}
	}while(sh != 4);
	return 0;
}
