typedef struct node
{
	int data;
	struct *node
}node;

int count_nodes(node *start);
node *reverse(node *start);
node *insert(node *start);
node *delete(node *start);
void display(node *start);

node *insert_front(node *start, int data);
node *insert_mid(node *start, int data, int pos);
node *insert_end(node *start, int data);

node *delete_front(node *start);
node *delete_pos(node *start, int pos);
node *delete_end(node *start);
node *delete_value(node *start);


int main()
{

	int choice=-1;

	node *start;
	start = NULL;

	while(choice != 0)
	{
		printf("1.Insert Element\n/
			2.Delete Element\n/
			3.Display\n/
			4.Count number of data\n/
			5.Reverse the list\n/
			0.Exit\n/
			");

		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1 : start = insert(start);
				 break;

			case 2 : start = delete(start);
				 break;

			case 3 : display(start);
				 break;

			case 4 : printf("The number of nodes in the current list is %d\n", count(start));
				 break;
			
			case 5 : head = reverse(start);
				 printf("The list has been reversed\n");
				 break;
			
			case 0 : break;

			default : printf("No such option. Please try again\n");
		}

	}

	return 0;
}
			

node *insert(node *start)
{
	int choice = -1, data, pos;

	printf("1.Insert at front\n/
		2.Insert at a position\n/
		3.Insert at the end\n/
		");
	scanf("%d", &choice);

	printf("Enter the data\n");
	scanf("%d", &data);

	switch(choice)
	{
		case 1 : start = insert_front(start, data);
			 break;
	
		case 2 : print("Enter the position\n");
			 scanf("%d", &pos);
			 start = insert_pos(start, data, pos);
			 break;

		case 3 : start = insert_end(start, data);

		default : printf("Invalid position\n");
	}

	return start;
}


