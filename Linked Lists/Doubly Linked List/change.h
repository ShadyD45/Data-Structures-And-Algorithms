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

void create_list(int no)
{
	struct node *temp,*q;
	
	temp=malloc(sizeof(struct node *));
	temp->data=no;
	temp->next=NULL;
	
	if(start==NULL)
	{
		temp->prev=NULL;
		start=temp;
		last=start;
	}
	else
	{
		last->next=temp;
		temp->prev=last;
		last = temp;
	}
}//End of create list

void addatbeg(int no)
{
	struct node *temp;
	temp=malloc(sizeof(struct node *));
	
	temp->data=no;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	printf("\nElement %d Added at beginning\n\n",no);
}//End of add at beginning

void addafter(int no,int p)
{
	struct node *temp,*q;
	int i;
	q=start;

	for(i=1;i<p-1;i++)
	{
		q=q->next;
		if(q->next==NULL)
		{
			printf("\nPlease enter valid position:(\n\n");
			return;		
		}
	}
	
	temp=malloc(sizeof(struct node *));
	temp->data=no;
	temp->next=q->next;
	temp->prev=q;
	q->next=temp;	
	printf("\nElement %d Added at position %d\n\n",no,p);
}//End of Add After

void del(int no)
{
	struct node *temp,*q;
	
	if(start->data==no)
	{
		temp=start;
		start=start->next; //first element deleted
		start->prev=NULL;
		free(temp);
		printf("\nElement %d deleted\n\n",no);
		return;	
	}
	q=start;

	while(q->next->next!=NULL)
	{
		if(q->next->data==no)	//To delete element in between
		{
			temp=q->next;
			q->next=temp->next;
			temp->next->prev=q;
			free(temp);
			printf("\nElement %d deleted\n\n",no);
			return;
		}
		
		q=q->next;	
	}

	if(q->next->data==no)	//To delete last element
	{
		temp=q->next;
		free(temp);
		q->next=NULL;
		last = q;
		printf("\nElement %d deleted\n\n",no);
		return;
	}
	
	printf("\nElement not %d found\n\n",no);
}//End of delete

void reverse()
{
	struct node *p1,*p2;
	p1=start;
	last=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;

	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	printf("\nList Reversed\n\n");	
}//End of reverse
