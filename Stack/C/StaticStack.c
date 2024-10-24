#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int iTop = -1;
int iarrStack[MAX];

void display();
void push(int);
void peek();
int pop();
int isFull();
int isEmpty();

void main()
{
	int iChoice, iItem;
	while(1)
	{
		printf("\n\tOPTIONS\t");
		printf("\n1) Push\n2) Pop\n3) Display\n4) Peek\n5) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to push onto the stack: ");
				scanf("%d",&iItem);
				push(iItem);
				break;
			case 2: if(isEmpty())
					{
						printf("\nStack underflow!!\n"); //not the best practice, as duplicates the code
					}
					else
					{
						printf("\n%d Popped from stack\n",pop());
					}
				break;
			case 3: display();
				break;
			case 4: peek();
				break;
			case 5: printf("Exiting.\n");
					exit(1);
			
			default: printf("\nWrong Choice!! Pleae enter valid input");				
		}
	}
}

void push(int data)
{
	if(isFull())
	{
		printf("\nStack Overflow!!");
		exit(1);
	}
	iTop += 1;
	iarrStack[iTop] = data;
}

int pop()
{
	int iItem;
	if(isEmpty())
	{
		printf("\nStack underflow!!");
	}
	iItem = iarrStack[iTop];
	iTop -= 1;
	return iItem;
}

void peek()
{
	if(isEmpty())
	{
		printf("\nStack is empty!!");
		return;
	}
	
	printf("\nItem at the Top is: %d\n\n",iarrStack[iTop]);
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("\nStack is empty!!");
		return;
	}
	else
	{
		printf("\n\tStack elements:\n");
		for(i = iTop; i >= 0; --i)
		{
			printf("\t%d\n",iarrStack[i]);
		}
	}
	printf("\n");
}

int isEmpty()
{
	if(iTop == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(iTop == (MAX - 1))
		return 1;
	else
		return 0;
}
