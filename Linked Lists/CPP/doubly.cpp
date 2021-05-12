using namespace std;

#include<iostream>

typedef struct node
{
	struct node *next;
	int iData;
	struct node *prev;
}NODE, *PNODE;

class DoublyLL
{
	private:
		PNODE Head;
		int iSize;
		
	public:
		DoublyLL()	// Default Constructor
		{
			Head = NULL;
			iSize = 0;
		}
		
		int Count()
		{
			return iSize;
		}
	
		void Display()
		{
			PNODE Temp = Head;
			cout<<"NULL=>";
			while(Temp != NULL)
			{
				cout<<"| "<<Temp->iData<<" |<=>";
				Temp = Temp->next;
			}
			cout<<"NULL"<<endl;
		}
			
		void InsertFirst(int iNum)
		{
			PNODE newn = NULL;
			
			newn = new NODE;
			newn->next = NULL;
			newn->iData = iNum;
			newn->prev = NULL;
			
			if(NULL == Head)	// LL is empty
			{
				Head = newn;
			}
			else				// LL contains atleast one node
			{
				newn->next = Head;
				Head->prev = newn;
				Head = newn;
			}
			iSize++;
		}
		
		void InsertLast(int iNum)
		{
			PNODE newn = NULL;
			PNODE Temp = Head;
			
			newn = new NODE;
			newn->next = NULL;
			newn->iData = iNum;
			newn->prev = NULL;
			
			if(NULL == Head)	// LL is empty
			{
				Head = newn;
			}
			else				// LL contains atleast one node
			{
				while(Temp->next != NULL)
				{
					Temp = Temp->next;
				} // End of while
				
				Temp->next = newn;
				newn->prev = Temp;
			}
			iSize++;
		}
		
		void InsertAt(int iNum, int iPos)
		{
			if(iPos < 1 || iPos > iSize+1)
			{
				return;
			}
			
			PNODE newn = NULL;
			PNODE Temp = Head;
			
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
				newn = new NODE;
				newn->next = NULL;
				newn->prev = NULL;
				newn->iData = iNum;
				
				for(int iCnt = 1; iCnt < iPos-1; ++iCnt)
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
		
		void DeleteFirst()
		{
			if(NULL != Head)
			{
				PNODE Temp = Head;
				Head = Head->next;
				Head->prev = NULL;
				delete Temp;
				iSize--;
			}
		}
		
		void DeleteLast()
		{
			if(NULL == Head)
			{
				return;
			}
			else if(NULL == Head->next)
			{
				delete Head;
				Head = NULL;
				iSize--;
			}
			else
			{
				PNODE Temp = Head;
				
				while(Temp->next->next != NULL)
				{
					Temp = Temp->next;
				} // End of while
				
				delete Temp->next;
				Temp->next = NULL;
				
				iSize--;
			}
		}
		
		void DeleteAt(int iPos)
		{
			if(iPos < 1 || iPos > iSize)
			{
				return;
			}
			
			PNODE Temp = Head;
			PNODE Target = NULL;
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
				for(int i = 1; i < iPos-1; i++)
				{
					Temp = Temp->next;
				}
				
				Temp->next = Temp->next->next;
				delete Temp->next->prev;
				Temp->next->prev = Temp;
				iSize--;
			}
		}
};


int main()
{
	int iRet = 0, iChoice = 1;
	int iValue = 0, iPos = 0;
	
	DoublyLL objList_1;
	
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
}
