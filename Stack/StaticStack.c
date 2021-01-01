#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int top = -1;
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
		printf("\n1) Push\n2) Pop\n3) Display\n4) Peek\n5) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to push onto the stack: ");
					scanf("%d",&iItem);
					push(iItem);
					break;
			case 2: printf("\n%d Popped from stack",pop());
					break;
			case 3: display();
					break;
			case 4: peek();
					break;
			case 5: exit(1);
			
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
	top += 1;
	iarrStack[top] = data;
}

int pop()
{
	int item;
	if(isEmpty())
	{
		printf("\nStack underflow!!");
		exit(1);
	}
	item = iarrStack[top];
	top -= 1;
	return item;
}

void peek()
{
	if(isEmpty())
	{
		printf("\nStack is empty!!");
		return;
	}
	
	printf("\nItem at the top is: %d",iarrStack[top]);
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
		for(i = top; i >= 0; --i)
		{
			printf("\t%d\n",iarrStack[i]);
		}
	}
	printf("\n");
}

int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(top == (MAX - 1))
		return 1;
	else
		return 0;
}
