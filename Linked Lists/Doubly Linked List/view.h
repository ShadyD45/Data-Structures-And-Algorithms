void display();
void count();

void display()
{
	struct node *q;
	
	if(start==NULL)
	{
		printf("\nList is empty");
		return;
	}
	q=start;
	
	printf("\nList is:-->");
	while(q!=NULL)
	{
		printf("\t %4d",q->data);
		q=q->next;
	}
	printf("\n\n");
}//End od Diplay

void count()
{
	struct node *q=start;
	int cnt=0;

	while(q!=NULL)
	{
		cnt++;
		q=q->next;
	}

	printf("\nThere are %d no. of elemenets in the list\n\n",cnt);
}
