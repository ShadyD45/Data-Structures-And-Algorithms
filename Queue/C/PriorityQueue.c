#include<stdio.h>
#include<stdlib.h>

struct node {
	int iItem;
	int iPriority;
	struct node *link;
}*front = NULL, *rear = NULL;

int isEmpty();
int del();
void display();
void insert(int, int);

void main()
{
	int iChoice, iItem, iPriority;
	while(1)
	{
		printf("\n1) Insert\n2) Delete\n3) Display\n4) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to insert in the queue: ");
					scanf("%d",&iItem);
					printf("\nEnter Priority: ");
					scanf("%d",&iPriority);
					insert(iItem, iPriority);
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

void insert(int iData, int iPrio)
{
	struct node *ptr;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	if(temp == NULL)
	{
		printf("\nNot enough memory\n");
		return;
	}
	temp->iItem = iData;
	temp->iPriority = iPrio;
	/* Queue is empty or item to be added has priority more than first item in queue */
	if(isEmpty() || iPrio < front->iPriority)
	{
		temp->link = front;
		front  = temp;
	}
	else
	{
		ptr = front;
		while(ptr->link!=NULL && ptr->link->iPriority <= iPrio)
		{
			ptr = ptr->link;
		}
		temp->link = ptr->link;
		ptr->link = temp;
	}
		
}

int del()
{
	int iItem;
	struct node *temp;
	if(isEmpty())
	{
		printf("\nQueue underflow\n");
		exit(1);
	}
	else
	{
		iItem = front->iItem;
		temp = front;
		front = front->link;
		free(temp);
	}
	return iItem;
}

void display()
{	
	struct node *ptr;
	if(isEmpty())
	{
		printf("\nQueue is empty!!\n");
		return;
	}
	else
	{
		ptr = front;
		printf("\nQueue: \n");
		printf("Priority	Item\n");
		while(ptr != NULL)
		{
			printf("   %d\t\t %d\n",ptr->iPriority,ptr->iItem);
			ptr = ptr->link;
		}
	}
	printf("\n");
}

int isEmpty()
{
	if(front == NULL)
		return 1;
	else
		return 0;
}



