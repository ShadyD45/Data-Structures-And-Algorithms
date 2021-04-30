#include<stdio.h>
#include<stdlib.h>

struct node {
	int iItem;
	struct node *Next;
};

typedef struct node PNODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int isEmpty();
int Delete(PPNODE);
void Insert(PPNODE, PPNODE, int);
void Display(PNODE);

void main()
{
	PNODE Front = NULL, Rear = NULL
	int iChoice = 0, iItem = 0;
	
	while(1)
	{
		printf("\n1) Insert\n2) Deleteete\n3) Display\n4) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to Insert in the queue: ");
					scanf("%d",&iItem);
					Insert(&Front, &Rear, iItem);
					break;
			case 2: printf("\n%d Deleteeted from queue",Delete(&Front, &Rear));
					break;
			case 3: Display(First);
					break;
			case 4: exit(1);
			
			default: printf("\nWrong Choice!! Pleae enter valid input\n");				
		}
	}
}

void Insert(int iData)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	if(temp == NULL)
	{
		printf("\nNot enough memory");
		return;
	}
	temp->iItem = iData;
	
	if(front == NULL)
		front = temp;
	else
		rear->link = temp;
	rear = temp;	
}

int Delete()
{
	int iItem;
	struct node *temp;
	if(isEmpty())
	{
		printf("\nQueue underflow");
		exit(1);
	}
	iItem = front->iItem;
	temp = front;
	front = front->link;
	free(temp);
	
	return iItem;
}

void Display()
{	
	struct node *ptr;
	if(isEmpty())
	{
		printf("\nQueue is empty!!");
		return;
	}
	else
	{
		ptr = front;
		printf("\nQueue: ");
		while(ptr != NULL)
		{
			printf("  %d",ptr->iItem);
			ptr = ptr->link;
		}
	}
	printf("\n");
}

int isEmpty()
{
	if(front == NULL)
		return -1;
	else
		return 0;
}
