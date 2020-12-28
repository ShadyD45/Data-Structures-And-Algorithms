void display();
void count();
void search(int);

void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	
	ptr=start;
	printf("List is:-->\n");
	while(ptr!=NULL)
	{
		printf("%4d",ptr->info);
		ptr=ptr->link;
	}
}//End of display function

void count()
{
	struct node *ptr=start;
	int cnt=0;
	
	while(ptr!=NULL)
	{
		ptr=ptr->link;
		cnt++;	
	}
	printf("There are %d elements in the list\n\n",cnt);
}//End of count function

void search(int data)
{
	struct node *ptr=start;
	int pos=1;
	
	while(ptr!=NULL)
	{
		if(ptr->info==data)
		{
			printf("Element %d found at %d postion\n\n",data,pos);
			return;
		}
		ptr=ptr->link;
		pos++;
	}

	if(ptr==NULL)
	{
		printf("Item %d not found in list\n\n");	
	}
}//End of search function
