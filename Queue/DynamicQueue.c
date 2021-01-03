#include<stdio.h>
#include<stdlib.h>

struct node {
	int iItem;
	struct node *link;
}*front = NULL, *rear = NULL;

int isEmpty();
int del();
void display();
void insert(int);

void main()
{
	int iChoice, iItem;
	while(1)
	{
		printf("\n1) Insert\n2) Delete\n3) Display\n4) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to insert in the queue: ");
					scanf("%d",&iItem);
					insert(iItem);
					break;
			case 2: printf("\n%d Deleted from queue",del());
					break;
			case 3: display();
					break;
			case 4: exit(1);
			
			default: printf("\nWrong Choice!! Pleae enter valid input\n");				
		}
	}
}

void insert(int iData)
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

int del()
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

void display()
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
