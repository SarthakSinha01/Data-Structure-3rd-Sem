#include <stdio.h>
#include <math.h>
#define MAX 1000
#define invalid(x) x=0; break

typedef struct {
	int top;
	int value[MAX];
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
			printf("|%7d|\n", s.value[s.top]);
			printf(" -------\n");
			s.top--;
		}
	}
}

void push(stack *s, int val)
{
	if(s->top == MAX)
		printf("%s\n","The Stack is FuLL which is highly Unlikely");
	else
	{
		s->top++;
		s->value[s->top] = val;
	}
}

int pop(stack *s)
{
	s->top--;
	return s->value[s->top+1];	
}

int operation(stack *s, char op)
{
	int sum, flag = 1;
	switch(op)
	{
		case '+':
			if(s->top <1){
	//			printf("Addition Error\n");
				invalid(flag);
			}
			else
			{
				sum = pop(s);
				sum += pop(s);
				push(s, sum);
			}
			break;

		case '-':
			if(s->top <1){
	//			printf("Sub Error\n");
				invalid(flag);
			}
			else
			{
				sum = pop(s);
				sum -= pop(s);
				push(s, -sum);
			}
			break;
		case '*':
			if(s->top <1){
	//			printf("Multi Error\n");
				invalid(flag);
			}
			else
			{
				sum = pop(s);
				sum *= pop(s);
				push(s, sum);	
			}
			break;

		case '/':
			if(s->top <1 || s->value[s->top] == 0){
	//			printf("Div Error\n");
				invalid(flag);
			}
			else
			{
				int n2 = pop(s);
				int n1 = pop(s);
				push(s, n1/n2);
			}
			break;

		case '^':
			if(s->top <1 || s->value[s->top] == 0)
				invalid(flag);
			sum = pop(s);
			sum = pow(sum, pop(s));
			break;
		default:
			invalid(flag);
	}
	display(*s);
	return flag;
}

int main()
{
	printf("Enter your Valid Postfix Expression : ");
	char expression[MAX];
	scanf("%s",expression);
	int i, flag = 1;
	int sum = 0;
	stack s;
	s.top = -1;
	for(i=0; expression[i] != '\0' && flag == 1; i++)
	{
	//	printf("Executing loop for i = %d\n", i);
	//	printf("At i = %d = %c\n", i, expression[i]);
		if(expression[i] >= '0' && expression[i] <= '9')
		{
			sum = sum*10 + (expression[i] - '0');
	//		printf("Printing ongoing Sum = %d\n", sum);
		}
		else
		{
	//		printf("Entering the else part !\n");
			if(expression[i] = ' ')
			{
	//			printf("Pushing = %d\n", sum);
				push(&s, sum);
				sum = 0;
			}
			else
				flag = operation(&s, expression[i]);
		}
	}
	if(!flag || s.top!=0)
		printf("Invalid Expression\n");
	else
		printf("Value of This Expression is %d\n", s.value[0]);
	return 0;
}