#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

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
		if(i == pos-1)
			last = temp->link;
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
