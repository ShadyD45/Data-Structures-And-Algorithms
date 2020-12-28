#include<stdio.h>
#include<stdlib.h>
#include"change.h"
#include"view.h"

int main()
{
	int choice,n,m,position,i;
	
	while(1)
	{
		printf("\nWhat Do you want to do?\n");
		printf("1.Create List\n");
		printf("2.Add at beginning\n");
		printf("3.Inser At\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Count\n");
		printf("7.Reverse\n");
		printf("8.Search\n");
		printf("9.Quit\n");
		printf("Enter your choice:-->");
		scanf("%d",&choice);
		
		
		switch(choice)
		{
			case 1:	printf("\nHow many elements you want:-->");
					scanf("%d",&n);
					
					printf("\nEnter the elements:-->");
					for(i=0;i<n;i++)
					{
						scanf("%d",&m);
						CreateList(m);		
					}
					break;

			case 2:	printf("\nEnter The Element To Add:-->");
					scanf("%d",&m);
					AddAtBeg(m);	
					break;

			case 3:	printf("\nEnter The Element To Add:-->");
					scanf("%d",&m);
					
					printf("\nEnter position:-->");
					scanf("%d",&position);
					InsertAt(m,position);	
					break;

			case 4:	if(start==NULL)
					{
						printf("\nList is empty...");
					}	
							
					printf("\nEnter element to delete:-->");
					scanf("%d",&m);

					del(m);	
					break;

			case 5:	display();	 
					break;
			
			case 6: count();	
					break;

			case 7: reverse();	
					break;

			case 8: printf("\nEnter Element To Search:-->");
					scanf("%d",&m);
					search(m);	
					break;

			case 9: exit(1);

			default: printf("WRONG OPTION\n");
				
		}
	}
}


void CreateList(int data)
{
	struct node *ptr,*temp;
	temp=malloc(sizeof(struct node *));
	temp->info=data;
	temp->link=NULL;	//if list only has single element

	if(start==NULL)
	{
		start = temp;
		last  = start;
	}
	else
	{
		last->link = temp;
		last = temp;
	}
}//End Of Create List function


void AddAtBeg(int data)
{
	struct node*temp;
	temp=malloc(sizeof(struct node *));
	temp->info=data;	
	temp->link=start;
	start=temp;	
	printf("Element %d added at beginning\n\n",data);
}//End of Add at begining function


void InsertAt(int data,int pos)
{
	struct node *temp,*ptr;
	int i;
	ptr=start;
	
	if(ptr == NULL)
	{
		printf("List is empty!!\n");
		return;
	}
	else if(pos == 1)
	{
		AddAtBeg(data);
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->link;
			if(ptr==NULL)
			{
				printf("Please enter less position \n");
				return;
			}
		}
		temp=malloc(sizeof(struct node *));
		temp->link = ptr->link;
		temp->info = data;
		ptr->link = temp;
		printf("Element %d added at %d position\n\n",data,pos);
	}
}//End of add after function

void del(int data)
{
	struct node *temp,*ptr;
	
	if(start == NULL)
	{
		printf("List is empty!!\n");
		return;
	}		
	
	if(start->info == data) /* Deletion of first node*/
	{
		temp = start;
		start = start->link;
		free(temp);
		return;
	}
	
	ptr = start;	/* Deletion in between or at end */
	while(ptr->link != NULL)
	{
		if(ptr->link->info == data)
		{
			temp = ptr->link;
			
			if(temp->link == NULL)
				last = ptr;
				
			ptr->link = temp->link;
			free(temp);
			return;
		}
		ptr = ptr->link;
	}
	printf("Element %d not found\n",data);	
}//End of delete function

void reverse()
{
	struct node *prev, *ptr, *next;
	prev = NULL;
	ptr = start;
	last = start;
	while(ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	
	start = prev;
	printf("List is reversed\n\n");
}//End of reverse


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
