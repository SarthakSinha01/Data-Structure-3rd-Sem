#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node * create();

struct node * insert_at_front(struct node *head, int data);
struct node * insert_at_end(struct node *head, int data);
struct node * insert_at_pos(struct node *head, int pos, int data);
	
struct node * del_from_front(struct node *head);
struct node * del_from_end(struct node *head);
struct node * del_from_pos(struct node *head, int pos);
struct node * del_by_val(struct node *head, int val);

void display(struct node *head);

int main()
{
	int data, val, pos;
	int choice = 0;

	struct node *head = NULL;
	
	while (choice != 9)
	{
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Insert at position\n");
		printf("4. Delete from front\n");
		printf("5. Delete from end\n");
		printf("6. Delete from position\n");
		printf("7. Delete by value\n");
		printf("8. Display\n");
		printf("9. Exit\n");
		
		printf("Enter the choice : >> ");
		scanf("%d", &choice);
		
		switch (choice)
		{	
			case (1) : printf("Enter the data >> ");
				   scanf("%d", &data);
				   head = insert_at_front(head, data);
				   display(head);
					break;

			case (2) : printf("Enter the data >> ");
				   scanf("%d", &data);
				   head = insert_at_end(head, data);
			 	   display(head);
					break;

			case (3) : printf("Enter the position and value >> ");
				   scanf("%d %d", &pos, &data);
				   head = insert_at_pos(head, pos, data);
				   display(head);
					break;
			
			case (4) : head = del_from_front(head);
				   display(head);
					break;
		
			case (5) : head = del_from_end(head);
				   display(head);
					break;
			
			case (6) : printf("Enter the position to be deleted >> ");
				   scanf("%d", &pos);
				   head = del_from_pos(head, pos);
				   display(head);
					break;
			
			case (7) : printf("Enter the value to be deleted >> ");
				   scanf("%d", &val);
				   head = del_by_val(head, val);
				   display(head);
					break;
		
			case (8) : display(head);
					break;
			
			case (9) : break;
			
			default : printf("Error\n");
		}
	}
	printf("\n");
	return 0;
}

struct node *create()
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	return p;
}

struct node * insert_at_front(struct node * head, int data)
{
	struct node *p;	
	p = create();
	
	p -> data = data;
	p -> next = head;
	head = p;

	return head;
}
struct node * insert_at_end(struct node * head, int data)
{
	struct node * curr, *new;
	struct node * prev = NULL;
	
	new = create();
	curr = head;
	new -> data = data;

	while(curr != NULL)
	{
		prev = curr;
		curr = curr -> next;
	}
	if(prev != NULL)
		prev -> next = new;
	else
		head = new;
		 
	return head;
}
struct node * insert_at_pos(struct node *head, int pos, int data)
{
	struct node *curr, *prev, *new;
	prev = NULL;
	curr = head;
	
	new = create();
	new -> data = data;
	if(pos == 1)
	{
		head = insert_at_front(head, data);
		return head;
	}
	int i = 1;

	while(i<pos && curr != NULL)
	{
		prev = curr;
		curr = curr -> next;
		i++;
	}
	if(i == pos)
	{
		if(curr != NULL)
		{
			prev -> next = new;
			new -> next = curr;
		}
		else
		{
			head = insert_at_end(head, data);
			return head;
		}
	}
	else
		printf("Invalid Position\n");

	return head;
	
}
struct node * del_from_front(struct node *head)
{
	struct node *ptr;
	
	if(head != NULL)
	{
		ptr = head;
		head = head -> next;
		free(ptr);
	}
	else
		printf("Empty List\n");
	
	return head;
}
struct node * del_from_end(struct node *head)
{
	struct node *curr, *prev;
	
	curr = head;
	prev = NULL;
	
	if(curr == NULL)
	{
		printf("Empty List\n");
		return head;
	}
	while(curr -> next != NULL)
	{
		prev = curr;
		curr = curr -> next;
	}
	if(prev == NULL)
	{
		free(curr);
		curr = NULL;
		return curr;
	}

	prev -> next = NULL;
	free(curr);
	
	return head;
}
struct node * del_from_pos(struct node *head, int pos)
{
	struct node *prev, *curr;
	
	curr = head;
	prev = NULL;
	int i = 1;
	
	if(curr == NULL)
	{
		printf("Empty List\n");
		return head;
	}
	if(pos == 1)
	{
		head = del_from_front(head);
		return head;
	}
	while(i<pos && curr != NULL)
	{
		prev = curr;
		curr = curr -> next;
		i++;
	}
	if(i == pos)
	{
		if(curr != NULL)
		{
			prev -> next = curr -> next;
			free(curr);
		}
		else
		{
			head = del_from_end(head);
		}
	}
	else
	{
		printf("Invalid Position\n");
	}
	return head;
}
struct node * del_by_val(struct node *head, int val)
{
	struct node *prev, *curr, *ptr;
	int deleted = 0;
	
	curr = head;
	prev = NULL;
	
	if(curr == NULL)
	{
		printf("Empty List\n");
		return head;
	}
	while(curr != NULL)
	{
		if(curr -> data == val)
		{
			if(prev != NULL)
			{
				prev -> next = curr -> next;
				free(curr);
				deleted = 1;
			}
			else
			{
				ptr = curr;
				curr = curr -> next;
				free(ptr);
				head = curr;
				deleted = 1;
			}
		}
		else
		{
			prev = curr;
			curr = curr -> next;
		}
	}
	if(!deleted)
		printf("\n%d does not exist in the list\n", val);

	return head;
}
void display(struct node * head)
{
	if(head == NULL)
	{
		printf("\nEmpty List\n\n");
		return;
	}
	else
	{
		printf("\n ###########################################\n");
		while(head != NULL)
		{
			printf("%d -> ", head -> data);
			head = head -> next;
		}
		printf("\n ###########################################\n");
	}
}
