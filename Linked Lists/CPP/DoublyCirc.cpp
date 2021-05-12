using namespace std;

#include<iostream>

typedef struct node
{
	struct node *prev;
	int iData;
	struct node *next;
}NODE, *PNODE;

class DoublyCLL
{
	private:
		PNODE Head;
		PNODE Tail;
		int iSize;

	public:
		DoublyCLL()
		{
			Head = NULL;
			Tail = NULL;
			iSize = 0;
		}
		
		void Display();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAt(int,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAt(int);
		int  Count();
};

void DoublyCLL :: Display()
{
	int i = 0;
	PNODE Temp = Head;
	cout<<"TAIL=>";
	for(i = 1; i <= iSize; ++i)
	{
		cout<<"| "<<Temp->iData<<" |=>";
		Temp = Temp->next;
	}
	cout<<"HEAD"<<endl;
}
	
void DoublyCLL :: InsertFirst(int iNum)
{
	PNODE newn = new NODE;
	newn->next = NULL;
	newn->iData = iNum;
	newn->prev = NULL;
			
	if(Head == NULL && Tail == NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->next = Head;
		Head->prev = newn;
		Head = newn;
	}		
	Tail->next = Head;
	Head->prev = Tail;
	iSize++;
}

void DoublyCLL :: InsertLast(int iNum)
{
	PNODE newn = NULL;
			
	newn = new NODE;
	newn->next = NULL;
	newn->iData = iNum;
	newn->prev = NULL;
			
	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}	
	Head->prev = Tail;
	Tail->next = Head;
	iSize++;
}

void DoublyCLL :: InsertAt(int iNum, int iPos)
{
	if((iPos < 1) || (iPos > iSize + 1))
	{
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(iNum);
	}
	else if(iPos == iSize + 1)
	{
		InsertLast(iNum);
	}
	else
	{
		PNODE newn = new NODE;
		newn->iData = iNum;
		newn->next = NULL;
		newn->prev = NULL;
		
		PNODE Temp = Head;
		
		for(int i = 1; i < iPos - 1; i++)
		{
			Temp = Temp->next;
		}
		
		newn->next = Temp->next;
		Temp->next->prev = newn;
		Temp->next = newn;
		newn->prev = Temp;
		iSize++;
	}
}

void DoublyCLL :: DeleteFirst()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;	
	}
	else
	{
		Head = Head->next;
		delete Head->prev;
		Head->prev = Tail;
		Tail->next = Head;
	}
	iSize--;
}

void DoublyCLL :: DeleteLast()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Tail;
		Head = NULL;
		Tail = NULL;	
	}
	else
	{
		Tail = Tail->prev;
		delete Tail->next;
		Tail->next = Head;
		Head->prev = Tail;
	}
	iSize--;
}

void DoublyCLL :: DeleteAt(int iPos)
{
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE Temp = Head;
		
		for(int i = 1; i < iPos - 1; i++)
		{
			Temp = Temp->next;
		}
		Temp->next = Temp->next->next;
		delete Temp->next->prev;
		Temp->next->prev = Temp;
		iSize--;
	}
}

int DoublyCLL :: Count()
{
	return iSize;
}

int main()
{
	int iRet = 0, iChoice = 1;
	int iValue = 0, iPos = 0;
	
	DoublyCLL objList_1;
	
	while(iChoice != 0)
	{
		printf("**********************************************\n");
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
		printf("**********************************************\n");
			
		switch(iChoice)
		{
			case 1: cout<<"Enter element to insert: ";
					cin>>iValue;
					
					objList_1.InsertFirst(iValue);
					break;

			case 2: cout<<"Enter element to insert: ";
					cin>>iValue;
					
					objList_1.InsertLast(iValue);
					break;
			
			case 3: cout<<"Enter element to insert: ";
					cin>>iValue;
					
					cout<<"Enter Position: ";
					cin>>iPos;
					
					objList_1.InsertAt(iValue, iPos);
					break;	
					
			case 4: objList_1.DeleteFirst();
					break;
			
			case 5: objList_1.DeleteLast();
					break;
			
			case 6: cout<<"Enter Position: ";
					cin>>iPos;
					
					objList_1.DeleteAt(iPos);
					break;
			
			case 7:	cout<<"Nodes in linked list are:\n";
					objList_1.Display();
					break;
					
			case 8: iRet = objList_1.Count();
					printf("Number of nodes are: %d\n",iRet);
					break;
						
			case 0: printf("Thankyou for using!!\n");
					break;

			default: printf("Please enter valid choice\n");
					 break;
		} // End of switch
	} // End of while
	return 0;
	return 0;
}
