#include<stdio.h>
#include<stdlib.h>

struct node * insert(struct node * head, int data);
struct node * create();
int count(struct node * head);
void display(struct node * head);
struct node * reverse(struct node *head);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	int data, choice=0;
	int n;
	struct node *head = NULL;
	struct node *head_rev = NULL;
	
	printf("1. Insert new data\n");
	printf("2. Display\n");
	printf("3. Count\n");
	printf("4. Reverse\n");
	printf("5. Exit\n");
	
	while(choice != 5)
	{
		printf("Enter the choice >> ");
		scanf("%d", &choice);

		switch (choice)
		{
			case (1) : printf("Enter the data >> ");
				   scanf("%d", &data);
			   	   head = insert(head, data);
		   		   break;

			case (2) : printf("LIST :-\n");
				   display(head);
				   printf("REVERSED LIST :-\n");
				   head_rev = reverse(head);
				   display(head_rev);
				   break;
		
			case (3) : n = count(head);
				   printf("Total Nodes = %d\n", n);
				   break;
		
			case (4) : head_rev = reverse(head);
				   break;
			case (5) : break;
			default : printf("Error \n");
		}
	}
	
	return 0;
}

struct node *create()
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	return p;
}

struct node * insert(struct node *head, int data)
{
	struct node *p;
	p = create();
	p -> data = data;
	p -> next = head;
	head = p;
	
	return head;
}
int count(struct node * head)
{
	int count = 0;
	struct node *curr;
	
	curr = head;
	while(curr != NULL)
	{
		curr = curr -> next;
		count++;
	}
	
	return count;
}

void display(struct node *head)
{
	if(head == NULL)
	{
		printf("Empty List\n");
		return;
	}
	while(head != NULL)
	{
		printf("%d -> ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

struct node * reverse(struct node *head)
{
	struct node *curr;
	struct node *headrev = NULL;

	curr = head;
	
	while(curr != NULL)
	{
		headrev = insert(headrev, curr -> data);
		curr = curr -> next;
	}
	return headrev;
}
		
