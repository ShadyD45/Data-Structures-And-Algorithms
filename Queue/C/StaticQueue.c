#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int iarrQueue[MAX];
int iFront = -1;
int iRear = -1;

int isEmpty();
int isFull();
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
	if(isFull())
	{
		printf("\nQueue overflow");
		exit(1);
	}
	
	if(iFront == -1)
		iFront = 0;
		
	iRear = iRear + 1;
	iarrQueue[iRear] = iData;
}

int del()
{
	if(isEmpty())
	{
		printf("\nQueue underflow");
		exit(1);
	}
	
	int iData = iarrQueue[iFront];
	iFront += 1;
	
	return iData;	
}

void display()
{	
	int i;
	if(isEmpty())
	{
		printf("\nQueue is empty!!");
		return;
	}
	else
	{
		printf("\nQueue: ");
		for(i = iFront; i <= iRear; ++i)
		{
			printf("  %d",iarrQueue[i]);
		}
	}
	printf("\n");
}

int isFull()
{
	if(iRear == MAX -1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if((iRear == -1 && iFront == -1) || (iFront > iRear))
		return 1;
	else
		return 0;	
}

