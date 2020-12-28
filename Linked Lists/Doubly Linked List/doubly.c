#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"change.h"
#include"view.h"

int main()
{
	int choice,n,m,p,i;
	
	while(1)
	{
		printf("What Do you want to do?\n");
		printf("1.Create List\n");
		printf("2.Add at beginning\n");
		printf("3.Add after\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Count\n");
		printf("7.Reverse\n");
		printf("8.Quit\n");
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
					create_list(m);		//calling create list function
				}
				break;

			case 2:	printf("\nEnter The Element To Add:-->");
				scanf("%d",&m);
				addatbeg(m);	//calling addatbeg function	
				break;

			case 3:	printf("\nEnter The Element To Add and Position:-->");
				scanf("%d %d",&m,&p);
				addafter(m,p);	//calling addafter function
				break;

			case 4:	printf("\nEnter element to delete:-->");
				scanf("%d",&m);

				del(m);	//calling delete function
				break;

			case 5:	display();	//calling display function 
				break;
			
			case 6: count();	//calling count function
				break;

			case 7: reverse();	//calling reverse function
				break;

			case 8: exit(1);
				break;

			default: printf("WRONG OPTION!! Please choose correct option\n");
				
		}
	}
}

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
