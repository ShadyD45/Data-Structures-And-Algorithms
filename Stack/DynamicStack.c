#include<stdio.h>
#include<stdlib.h>
struct node
{
	int iItem;
	struct node *link;
}*top = NULL;

void display();
void push(int);
int peek();
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
			case 4: printf("\nItem at the Top is: %d",peek());
					break;
			case 5: exit(1);
			
			default: printf("\nWrong Choice!! Pleae enter valid input");				
		}
	}
}

void push(int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("\nStack Overflow!!");
		exit(1);
	}
	temp->iItem	= data;
	temp->link = top;
	top = temp;
}

int pop()
{
	int iData;
	struct node *temp;
	if(isEmpty())
	{
		printf("\nStack underflow!!");
		exit(1);
	}
	
	iData = top->iItem;
	temp = top;
	top = top->link;
	free(temp);
	
	return iData;
}

int peek()
{
	if(isEmpty())
	{
		printf("\nStack underflow!!");
		exit(1);
	}
	return top->iItem;
}

void display()
{
	int i;
	struct node *ptr;
	if(isEmpty())
	{
		printf("\nStack is empty!!");
		return;
	}
	else
	{
		for(ptr = top; ptr != NULL; ptr = ptr->link)
		{
			printf("\t%d\n",ptr->iItem);
		}
	}
	printf("\n");
}

int isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}
