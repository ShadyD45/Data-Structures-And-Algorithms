struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*start=NULL,*last=NULL;

void create_list(int);
void del(int);
void addatbeg(int);
void addafter(int,int);
void reverse();
