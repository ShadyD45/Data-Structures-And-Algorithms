#include<stdio.h>
#include<stdlib.h>

struct node {
	int iItem;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int isEmpty(PNODE);
int Delete(PPNODE);
void Insert(PPNODE, PPNODE, int);
void Display(PNODE);

void main()
{
	PNODE Front = NULL, Rear = NULL;
	int iChoice = 0, iItem = 0;
	
	while(1)
	{
		printf("\n1) Insert\n2) Delete\n3) Display\n4) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to Insert in the queue: ");
					scanf("%d",&iItem);
					Insert(&Front, &Rear, iItem);
					break;
			case 2: printf("\n%d Deleted from queue",Delete(&Front));
					break;
			case 3: Display(Front);
					break;
			case 4: exit(1);
			
			default: printf("\nWrong Choice!! Pleae enter valid input\n");				
		}
	}
}

void Insert(PPNODE Front, PPNODE Rear, int iData)
{
	PNODE temp = (PNODE)malloc(sizeof(NODE));
	
	if(NULL == temp)
	{
		printf("\nNot enough memory!");
		return;
	}
	
	temp->iItem = iData;
	
	if(isEmpty(*Front))		// If queue is empty
	{
		*Front = temp;
	}
	else					// If there is atleast one item in queue
	{
		(*Rear)->Next = temp;
	}
	*Rear = temp;	
}

int Delete(PPNODE Front)
{
	int iItem = 0;
	PNODE temp = NULL;
	
	if(isEmpty(*Front))
	{
		printf("\nQueue underflow\n");
		exit(1);
	}
	
	iItem = (*Front)->iItem;
	temp = *Front;
	*Front = (*Front)->Next;
	free(temp);
	
	return iItem;
}

void Display(PNODE Front)
{	
	PNODE temp = NULL;
	if(isEmpty(Front))
	{
		printf("\nQueue is empty!!");
		return;
	}
	else
	{
		temp = Front;
		printf("\nQueue: ");
		while(NULL != temp)
		{
			printf("  %d",temp->iItem);
			temp = temp->Next;
		}
	}
	printf("\n");
}

int isEmpty(PNODE Front)
{
	if(NULL == Front)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
