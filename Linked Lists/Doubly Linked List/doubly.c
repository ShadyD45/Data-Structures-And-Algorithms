#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *prev;
	int iData;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void InsertAt(PPNODE, int, int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAt(PPNODE, int);
void Display(PNODE);
int  Count(PNODE);

void InsertFirst(PPNODE Head, int iNum)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->next = NULL;
	newn->iData = iNum;
	newn->prev = NULL;
	
	if(NULL == *Head)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head, int iNum)
{
	PNODE Temp = *Head;
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	newn->next = NULL;
	newn->iData = iNum;
	newn->prev = NULL;
	
	if(NULL == *Head)
	{
		*Head = newn;
	}
	else
	{
		while(NULL != Temp->next)
		{
			Temp = Temp->next;
		}
		Temp->next = newn;
		newn->prev = Temp;
	}
}

void InsertAt(PPNODE Head, int iNum, int iPos)
{
	int iSize = 0, iCnt = 0;
	PNODE Temp = *Head, newn = NULL;
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > (iSize + 1)) || (NULL == (*Head)))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head, iNum);
	}
	else if(iPos == iSize)
	{
		InsertLast(Head, iNum);
	}
	else
	{	
		newn = (PNODE)malloc(sizeof(NODE));
		newn->next = NULL;
		newn->prev = NULL;
		newn->iData = iNum;
		
		for(iCnt = 1; iCnt < iPos-1; ++iCnt)
		{
			Temp = Temp->next;
		}
		
		newn->next = Temp->next;
		Temp->next->prev = newn;
		Temp->next = newn;
		newn->prev = Temp;
	}
}

void DeleteFirst(PPNODE Head)
{
	if(NULL == *Head)				// Empty linked list	
	{
		return;
	}
	else if(NULL == (*Head)->next)	// Only one node in linked list
	{
		free(*Head);
		*Head = NULL;
	}
	else							// More than one node in linked list
	{
		*Head = (*Head)->next;
		free((*Head)->prev);
		(*Head)->prev = NULL;
	}
}

void DeleteLast(PPNODE Head)
{
	if(NULL == *Head)				// Empty linked list
	{
		return;
	}
	PNODE Temp = *Head;
	
	if(NULL == (*Head)->next)		// Only one node in linked list
	{
		free(*Head);
		*Head = NULL;
	}
	else							// More than one node in linked list
	{
		while(NULL != Temp->next->next)
		{
			Temp = Temp->next;
		}
		free(Temp->next);
		Temp->next = NULL;
	}
}

void DeleteAt(PPNODE Head, int iPos)
{
	int iSize = 0, iCnt = 0;
	PNODE Temp = *Head, Target = NULL;
	iSize = Count(*Head);
	
	if((iPos < 1) || (iPos > (iSize + 1)) || (NULL == (*Head)))
	{
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{	
		for(iCnt = 1; iCnt < iPos-1; ++iCnt)
		{
			Temp = Temp->next;
		}
		
		Target = Temp->next;
		Temp->next = Target->next;
		Target->next->prev = Temp;
		free(Target);
	}
}

void Display(PNODE Head)
{
	printf("NULL<=>");
	while(NULL != Head)
	{
		printf("| %d |<=>",Head->iData);
		Head = Head->next;	
	}
	
	printf("NULL\n");
}

int Count(PNODE Head)
{
	int iCnt = 0;
	
	while(NULL != Head)
	{
		iCnt++;
		Head = Head->next;	
	}
	
	return iCnt;
}

int main()
{
	PNODE First = NULL;
	
	int iRet = 0, iChoice = 1, iValue = 0, iPos = 0;
	
	while(iChoice != 0)
	{
		printf("*********************************************\n");
		printf("1. Insert First\n");
		printf("2. Insert Last\n");
		printf("3. Insert At Position\n");
		printf("4. Delete First\n");
		printf("5. Delete Last\n");
		printf("6. Delete At Position\n");
		printf("7. Display\n");
		printf("8. Count\n");
		printf("0. Exit\n");
		printf("Enter you action on linked list: ");
		scanf("%d",&iChoice);
		printf("*********************************************\n");
		
		switch(iChoice)
		{
			case 1: printf("Enter element to insert: ");
					scanf("%d",&iValue);
					InsertFirst(&First, iValue);
					break;
					
			case 2: printf("Enter element to insert: ");
					scanf("%d",&iValue);
					InsertLast(&First, iValue);
					break;
			
			case 3: printf("Enter element to insert: ");
					scanf("%d",&iValue);
					printf("Enter Position: ");
					scanf("%d",&iPos);
					InsertAt(&First, iValue, iPos);
					break;
			
			case 4: DeleteFirst(&First);
					break;
		
			case 5: DeleteLast(&First);
					break;
			
			case 6: printf("Enter Position: ");
					scanf("%d",&iPos);
					DeleteAt(&First, iPos);
					break;
			
			case 7: printf("Contents of linked list are:\n");
					Display(First);
					break;
			
			case 8: iRet = Count(First);
					printf("Number of nodes: %d\n",iRet);
					break;
			
			case 0: printf("Thankyou for using!!\n");
					break;
					
			default: printf("\nWrong Choice! Please select valid option\n\n");
					 break;
		}
	}
	
	return 0;
}
