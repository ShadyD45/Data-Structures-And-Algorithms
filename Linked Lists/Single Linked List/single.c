#include<stdio.h>
#include<stdlib.h>

// We pass address of first pointer only to the functions which change linkedlist
struct node
{
	int iData;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void Display(PNODE);
int Count(PNODE);
void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void InsertAt(PPNODE, int, int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);


void InsertFirst(PPNODE Head, int iNum)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	newn->iData = iNum;
	newn->Next = NULL;
	
	if(*Head == NULL)	// Linked List is empty
	{
		*Head = newn;
	}
	else				// Linked List contains atleast one node
	{
		newn->Next = *Head;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head, int iNum)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	newn->iData = iNum;
	newn->Next = NULL;
	
	if(*Head == NULL)	// Linked List is empty
	{
		*Head = newn;
	}
	else				// Linked List contains atleast one node
	{
		while(temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = newn;
	}
}

void InsertAt(PPNODE Head, int iNum, int iPos)
{
	PNODE temp = *Head;
	PNODE newn = NULL;
	int iCnt = 1;
	
	if(((*Head) == NULL) || (iPos > Count(*Head) + 1))		// If Linked List is empty
	{
		return;
	}
	else if(iPos == 1)					// If the user wants to add at 1st position
	{
		InsertFirst(Head, iNum);	// Just reuse the InsertFirst() we wrote
	}
	else
	{
		while(iCnt < iPos-1)
		{
			temp = temp->Next;
			iCnt++;
		}
		
		newn = (PNODE)malloc(sizeof(NODE));
		newn->iData = iNum;
		
		newn->Next = temp->Next;
		temp->Next = newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	if(*Head == NULL)					// If LinkedList is Empty
	{
		return;
	}
	else if((*Head)->Next == NULL)		// If LinkedList has single node
	{
		free(*Head);	// Delete first node
		*Head = NULL;	// Set First pointer to NULL
	}
	else								// If LinkedList has more than one node
	{
		*Head = (*Head)->Next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	if(*Head == NULL)					// If LinkedList is Empty
	{
		return;
	}
	else if((*Head)->Next == NULL)		// If LinkedList has single node
	{
		free(*Head);	// Delete First Node
		*Head = NULL;	// Set First Pointer to NULL
	}
	else								// If LinkedList has more than one node
	{
		while(temp->Next->Next != NULL)
		{
			temp = temp->Next;
		}
		free(temp->Next);
		temp->Next = NULL;
	}
}

void Display(PNODE Head)
{
	printf("\n");
	while(Head != NULL)
	{
		printf("| %d |->",Head->iData);
		Head = Head->Next;
	}
	printf("NULL\n");
}

int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->Next;
	}
	return iCnt;
}


int Search(PNODE Head, int iNum)
{
	int iCnt = 1;
	
	while(Head != NULL)
	{
		if(Head->iData == iNum)
		{
			break;
		}
		Head = Head->Next;
		iCnt++;
	}
	
	// Return -1 if element not found else return the position	
	if(Head == NULL)
	{
		return -1;
	}
	else
	{
		return iCnt;
	}
}


int main()
{
	PNODE First = NULL;
	int iNum = 0, iNo = 0;
	int iPos = 0, iChoice = 0;
	int iCnt = 0;
	
	while(1)
	{
		printf("\nWhat Do you want to do?\n");
		printf("1.Create List\n");
		printf("2.Add at beginning\n");
		printf("3.Insert At\n");
		printf("4.Append\n");
		printf("5.Delete First\n");
		printf("6.Delete Last\n");
		printf("7.Display\n");
		printf("8.Count\n");
		printf("9.Search\n");
		//printf("10.Reverse\n");
		//printf("11.Sort List By Exchanging Links\n");
		printf("10.Quit\n");
		printf("Enter your choice:-->");
		scanf("%d",&iChoice);
		
		
		switch(iChoice)
		{
			case 1:	printf("\nHow many elements you want:-->");
				scanf("%d",&iNo);
					
				printf("\nEnter the elements:-->");
				for(iCnt = 0; iCnt < iNo; iCnt++)
				{
					scanf("%d",&iNum);
					InsertLast(&First, iNum);		
				}
				break;

			case 2:	printf("\nEnter The Element To Add:-->");
				scanf("%d",&iNum);
				InsertFirst(&First, iNum);	
				break;
					
			case 4: printf("\nEnter the element:-->");
				scanf("%d",&iNum);
				InsertLast(&First, iNum);
				break;
					
			case 3:	printf("\nEnter The Element To Add:-->");
				scanf("%d",&iNum);
					
				printf("\nEnter position:-->");
				scanf("%d",&iPos);
					
				InsertAt(&First, iNum, iPos);	
				break;

			case 5:	DeleteFirst(&First);	
				break;

			case 6: DeleteLast(&First);
				break;

			case 7:	Display(First);	 
				break;
			
			case 8: iCnt = Count(First);
				printf("\nCount: %d\n",iCnt);	
				break;
					
			case 9: printf("\nEnter Element To Search:-->");
				scanf("%d",&iNum);
				iCnt = Search(First, iNum);
				if(iCnt == -1)
				{	
					printf("\nElement %d not found..\n",iNum);	
				}
				else
				{
					printf("\nElement %d found at position %d\n",iNum, iCnt);
				}
				break;
			/*case 10: reverse();	
					 break;

			case 11: SortByExchangingLinks(&First);
					break;*/
					
			case 10: free(First);
				 exit(1);
					 
			default: printf("WRONG OPTION\n");
				
		}
	}
	return 0;
}
