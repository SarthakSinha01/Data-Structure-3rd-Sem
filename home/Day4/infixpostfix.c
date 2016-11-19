#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef union
{
	double num;
	char operation;
}data_store;

typedef struct
{
	data_store data[100];
	int top;
}stack;

char *infix_to_postfix(char *input);
void push(stack *s, data_store d);
data_store pop(stack *s);
int is_operator(char c);
int priority(char op1, char op2);
double evaluate(char *output);
double operation(double n1, double n2, char op);

int valid(char *str);
int is_opening(char ch);
int is_closing(char ch);

int main()
{
	char input[100];
	char *output;
	double result;
	
	input[0] = '(';
	printf("Enter the infix expression \n");
	scanf("%s", input+1);

	int l = strlen(input);

	input[l] = ')';
	input[l + 1] = '\0';

	printf("%s\n", input);
	if(!valid(input))
		return 1;

	printf("%s\n", input);

	output = infix_to_postfix(input);

	if(output == NULL)
		return 2;

	result = evaluate(output);
	
	printf("%s\n", output);
	printf("%f\n", result);
	free(output);
	
	return 0;
}

char *infix_to_postfix(char *input)
{
	char *output;
	output = (char *)malloc(100 * sizeof(char));
	
	int i, j, n;
	n = strlen(input);
	
	stack s;
	s.top = -1;
	data_store op;
	
	j = 0;
	for(i = 0; i < n; i++)
	{
		if(input[i] == '(')
		{
			op.operation = '(';
			push(&s, op);
		}
		else if(input[i] == ')')
		{
			op = pop(&s);
			while(op.operation != '(')
			{
				output[j] = op.operation;
				op = pop(&s);
				j++;
			}
		}
		else if(is_operator(input[i]))
		{
			if(!priority((input[i]),  s.data[s.top].operation))
			{
				op = pop(&s);
				output[j] = op.operation;
				j++;
				op.operation = input[i];
				push(&s,  op);
			}
			else
			{
				op.operation = input[i];
				push(&s,  op);
			}
			output[j] = ' ';
			j++;
		}
		else if(isdigit(input[i]) || input[i] == '.')
		{
			output[j] = input[i];
			j++;
		}
		else
		{
			printf("Error at %dth character, %c is invalid.\n", i+1, input[i]);
			return NULL;
		}
	}
	output[j] = '\0';
	
	return output;
}

void push(stack *s, data_store d)
{
	s -> top ++;
	s -> data[s -> top] = d;
}

data_store pop(stack *s)
{
	data_store d = s -> data[s -> top];
	s -> top--;
	
	return d;
}

int is_operator(char ch)
{
	switch(ch)
	{
		case '+' : return 1;
		case '-' : return 1;
		case '*' : return 2;
		case '/' : return 2;
	}
	return 0;
}

int priority(char op1, char op2)
{
	int k;
	k =  is_operator(op1) > is_operator(op2) ? 1 : 0;
			
	return k;
}

double evaluate(char * output)
{
	data_store d1, d2;
	
	double result, num = 0;
	int i, n, read = 0;
	
	n = strlen(output);

	stack s;
	s.top = -1;
	float factor = 10;
	
	for(i = 0; i < n; i++)
	{	
		if(isdigit(output[i]))
		{
			if(factor < 1)
			{
				num = num + factor * (output[i] - 48);
				factor = factor/10;
			}
			else
			{
				num = num * factor + output[i] - 48;
			}
			read = 1;
		}
		else if(output[i] == '.')
		{
			factor = 0.1;
			read = 1;
		}
		else if(output[i] == ' ' && isdigit(output[i-1]))
		{
			factor = 10;
			d1.num = num;
			push(&s, d1);
			num = 0;
			read = 0;
		}
		else if(is_operator(output[i]))
		{
			if(!is_operator(output[i-1]))
			{
				factor = 10;
				d1.num = num;
				push(&s, d1);
				num = 0;
				read = 0;
			}
			d1 = pop(&s);
			
			if(s.top == -1)
			{
				printf("Invalid operation :%c\nThe result is invalid.\n", output[i]);
				return 1;
			}
			d2 = pop(&s);
			
			result = operation(d2.num, d1.num, output[i]);
			
			d1.num = result;
			push(&s, d1);
		}
	}
	d1 = pop(&s);
	
	return d1.num;
}

double operation(double n1, double n2, char op)
{
	switch(op)
	{
		case '+' : return n1 + n2;
		case '-' : return n1 - n2;
		case '*' : return n1 * n2;
		case '/' : return n1 / n2;
	}
}

int valid(char *str)
{
	stack s;
	s.top = -1;
	data_store d;
	
	int i, n;
	n = strlen(str);
	
	for(i=0; i<n; i++)
	{
		if(is_opening(str[i]))
		{
			d.operation = str[i];
			push(&s, d);
		}
		else if(is_closing(str[i]))
		{
			if(s.top == -1)
			{
				printf("Expected '(' before ')'\n");
				return 0;
			}
			d = pop(&s);
			
			if(is_opening(d.operation) != is_closing(str[i]))
			{
				printf("%c does not match with %c.\n", d.operation, str[i]);
				return 0;
			}
		}
	}
	if(s.top == -1)
		return 1;
	else
	{
		printf("Extra '('\n");
		return 0;
	}
}

int is_opening(char ch)
{
	switch (ch)
	{
		case '(' : return 1;
		case '{' : return 2;
		case '[' : return 3;
	}
	return 0;
}

int is_closing(char ch)
{
	switch (ch)
	{
		case ')' : return 1;
		case '}' : return 2;
		case ']' : return 3;
	}
	return 0;
}
