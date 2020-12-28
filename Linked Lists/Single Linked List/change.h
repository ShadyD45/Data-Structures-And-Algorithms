struct node
{
	int info;
	struct node *link;
}*start=NULL,*last=NULL;


void CreateList(int);
void AddAtBeg(int);
void InsertAt(int,int);
void del(int);
void reverse();
