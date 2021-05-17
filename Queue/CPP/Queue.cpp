#include<iostream>

using namespace std;

typedef struct Node
{
	int iData;
	struct Node *next;
}NODE, *PNODE;

class Queue
{
	private:
		PNODE Head;
		PNODE Tail;
		int iSize;
	
	public:
		Queue();		// Constructor
		~Queue();		// Destructor
		void Enqueue(int);
		int Dequeue();
		void Display();
		int Count();
		int Front();
};

Queue :: Queue()	// Constructor
{
	this->Head = NULL;
	this->Tail = NULL;
	this->iSize = 0;
}

Queue :: ~Queue()	// Destructor
{
	PNODE Temp = NULL;
	
	while(Head != NULL)
	{
		Temp = Head;
		Head = Head->next;	
		delete Temp;
	}
}

void Queue :: Enqueue(int iNum)
{
	PNODE newn = new NODE;
	newn->next = NULL;
	newn->iData = iNum;
	
	if(iSize == 0)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{	
		Tail->next = newn;
		Tail = newn;
	}
	iSize++;
}

int Queue :: Dequeue()
{
	int iRet = -1;
	
	if(iSize == 0)
	{
		cout<<"Queue is empty!"<<endl;
	}
	else
	{
		PNODE Temp = Head;
		iRet = Head->iData;
		Head = Head->next;
		delete Temp;
		iSize--;
	}
	return iRet;
}

int Queue :: Front()
{
	if(iSize == 0)
	{
		cout<<"Queue is empty"<<endl;
		return -1;
	}
	return this->Head->iData;
}

void Queue :: Display()
{
	PNODE Temp = Head;
	while(Temp != NULL)
	{
		cout<<"\t"<<Temp->iData;
		Temp = Temp->next;
	}
	cout<<endl;
}

int Queue :: Count()
{
	return this->iSize;
}

int main()
{
	// Dynamic object creation
	Queue *objQueue = new Queue;	// It implicitily calls constructor
	
	int iChoice = 1, iRet = 0, iNo = 0;
	
	while(iChoice != 0)
	{
		cout<<"*************************************"<<endl;
		cout<<"Please select an operation: "<<endl;
		cout<<"1) Enqueue"<<endl;
		cout<<"2) Dequeue"<<endl;
		cout<<"3) Display"<<endl;
		cout<<"4) Count"<<endl;
		cout<<"5) Peek"<<endl;
		cout<<"0) Exit"<<endl;
		cout<<"Enter your action: ";
		cin>>iChoice;
		cout<<"*************************************"<<endl;
		
		switch(iChoice)
		{
			case 1:	cout<<"Enter element to insert: ";
					cin>>iNo;
					objQueue->Enqueue(iNo);
					break;
					
			case 2:	iRet = objQueue->Dequeue();
					cout<<"Deleted element is: "<<iRet<<endl;
					break;
			
			case 3: cout<<"Queue is: "<<endl;
					objQueue->Display();
					break;
			
			case 4: iRet = objQueue->Count();
					cout<<"Size of Queue is: "<<iRet<<endl;
					break;
			
			case 5:	iRet = objQueue->Front();
					cout<<"Top element is: "<<iRet<<endl;
					break;
					
			case 0:	cout<<"Thankyou for using!!"<<endl;
					delete objQueue;	// It implicitily calls destructor
					break;

			default: cout<<"Please select valid option!"<<endl;
					 break;
		}
	}
	
	return 0;
}
