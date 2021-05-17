#include<stdio.h>
#include<stdlib.h>

struct node
{
	int iItem;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE);
void push(PPNODE, int);
int peek(PNODE);
int pop(PPNODE);
int isEmpty(PNODE);

void main()
{
	int iChoice, iItem;
	PNODE Top = NULL;
	
	while(1)
	{
		printf("\n1) Push\n2) Pop\n3) Display\n4) Peek\n5) Quit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	printf("\nEnter item to push onto the stack: ");
					scanf("%d",&iItem);
					push(&Top, iItem);
					break;
			case 2: printf("\n%d Popped from stack",pop(&Top));
					break;
			case 3: Display(Top);
					break;
			case 4: printf("\nItem at the Top is: %d",peek(Top));
					break;
			case 5: exit(1);
			
			default: printf("\nWrong Choice!! Pleae enter valid input");				
		}
	}
}

void push(PPNODE Top, int iData)
{
	PNODE temp;
	temp = (PNODE)malloc(sizeof(NODE));
	if(NULL == temp)
	{
		printf("\nStack Overflow!!\n");
		exit(1);
	}
	temp->iItem = iData;
	temp->Next = *Top;
	*Top = temp;
}

int pop(PPNODE Top)
{
	int iData = -1;
	PNODE temp;
	
	if(isEmpty(*Top))
	{
		printf("\nStack underflow!!\n");
		exit(1);
	}
	
	iData = (*Top)->iItem;
	temp = *Top;
	*Top = (*Top)->Next;
	free(temp);
	
	return iData;
}

int peek(PNODE Top)
{
	if(isEmpty(Top))
	{
		printf("\nStack underflow!!\n");
		exit(1);
	}
	return Top->iItem;
}

void Display(PNODE Top)
{
	int i;
	PNODE ptr = NULL;
	
	if(isEmpty(Top))
	{
		printf("\nStack is empty!!\n");
		return;
	}
	else
	{
		ptr = Top;
		while(NULL != ptr)
		{
			printf("\t%d\n",ptr->iItem);
			ptr = ptr->Next;
		}
	}
	printf("\n");
}

int isEmpty(PNODE Top)
{
	if(NULL == Top)
		return 1;
	else
		return 0;
}
