#include<iostream>

using namespace std;

typedef struct Node
{
	int iData;
	struct Node *next;
}NODE, *PNODE;

class Stack
{
	private:
		PNODE Head;
		int iSize;
	
	public:
		Stack();		// Constructor
		~Stack();		// Destructor
		void Push(int);
		int Pop();
		int Peek();
		void Display();
		int Count();
};

Stack :: Stack()	// Constructor
{
	this->Head = NULL;
	this->iSize = 0;
}

Stack :: ~Stack()	// Destructor
{
	PNODE Temp = NULL;
	
	while(Head != NULL)
	{
		Temp = Head;
		Head = Head->next;	
		delete Temp;
	}
}

void Stack :: Push(int iNum)
{
	PNODE newn = new NODE;
	newn->next = NULL;
	newn->iData = iNum;
	
	newn->next = Head;
	Head = newn;
	iSize++;
}

int Stack :: Pop()
{	
	int iRet = -1;
	
	if(iSize == 0)		// If Stack is empty
	{
		cout<<"Stack is empty"<<endl;
	}
	else				// If stack has atleast one node
	{	
		iRet = Head->iData;
		PNODE Temp = Head;
		Head = Head->next;	
		delete Temp;
		iSize--;
	}
	return iRet;
}

int Stack :: Peek()
{
	if(iSize == 0)
	{
		cout<<"Stack is empty!"<<endl;
		return -1;	
	}
	return Head->iData;
}

void Stack :: Display()
{
	PNODE Temp = Head;
	while(Temp != NULL)
	{
		cout<<"\t\t"<<Temp->iData<<endl;
		Temp = Temp->next;
	}
}

int Stack :: Count()
{
	return this->iSize;
}

int main()
{
	// Dynamic object creation
	Stack *objStack = new Stack;	// It implicitily calls constructor
	
	int iChoice = 1, iRet = 0, iNo = 0;
	
	while(iChoice != 0)
	{
		cout<<"*************************************"<<endl;
		cout<<"Please select an operation: "<<endl;
		cout<<"1) Push"<<endl;
		cout<<"2) Pop"<<endl;
		cout<<"3) Display"<<endl;
		cout<<"4) Count"<<endl;
		cout<<"5) Peek"<<endl;
		cout<<"0) Exit"<<endl;
		cout<<"Enter your action: ";
		cin>>iChoice;
		cout<<"*************************************"<<endl;
		
		switch(iChoice)
		{
			case 1:	cout<<"Enter element to push: ";
					cin>>iNo;
					objStack->Push(iNo);
					break;
					
			case 2:	iRet = objStack->Pop();
					cout<<"Popped element is: "<<iRet<<endl;
					break;
			
			case 3: cout<<"Stack is: "<<endl;
					objStack->Display();
					break;
			
			case 4: iRet = objStack->Count();
					cout<<"Size of stack is: "<<iRet<<endl;
					break;
			
			case 5:	iRet = objStack->Peek();
					cout<<"Top element is: "<<iRet<<endl;
					break;
					
			case 0:	cout<<"Thankyou for using!!"<<endl;
					delete objStack;	// It implicitily calls destructor
					break;

			default: cout<<"Please select valid option!"<<endl;
					 break;
		}
	}
	
	return 0;
}
