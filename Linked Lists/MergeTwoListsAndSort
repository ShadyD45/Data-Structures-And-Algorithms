#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;	
};

struct node *MergeLists(struct node *, struct node *);
struct node *CreateList(struct node *, int);
struct node *insert(struct node *, int);
void display(struct node *start);

void main()
{
	struct node *startList1 = NULL, *startList2 = NULL;
	int n;
	
	printf("\nEnter no. of elements in 1st List: ");
	scanf("%d",&n);
	startList1 = CreateList(startList1, n);
	
	printf("\nEnter no. of elements in 2nd List: ");
	scanf("%d",&n);
	startList2 = CreateList(startList2, n);
	
	printf("\nList 1: ");
	display(startList1);
	
	printf("\nList 2: ");
	display(startList2);
	
	printf("\nMerged and Sorted List: ");
	display(MergeLists(startList1, startList2));
}

struct node *MergeLists(struct node *start1, struct node *start2)
{
	struct node *startMerged = NULL;
	
	while(start1 != NULL && start2 != NULL)
	{
		if(start1->info < start2->info)
		{
			startMerged = insert(startMerged, start1->info);
			start1 = start1->link;
		}
		else if(start2->info < start1->info)
		{
			startMerged = insert(startMerged, start2->info);
			start2 = start2->link;
		}
		else if(start1->info == start2->info)
		{
			startMerged = insert(startMerged, start1->info);
			start1 = start1->link;
			start2 = start2->link;
		}
	}
	
	/* If second list is finished then insert elements left first list */
	while(start1 != NULL)
	{
		startMerged = insert(startMerged, start1->info);
		start1 = start1->link;
	}
	
	/* If first list is finished then insert elements left second list */
	while(start2 != NULL)
	{
		startMerged = insert(startMerged, start2->info);
		start2 = start2->link;
	}
	return startMerged;
}

struct node *CreateList(struct node *start, int n)
{
	int i, data;
	
	printf("\nEnter the elements in the list: ");
	for(i = 0; i < n; ++i)
	{
		scanf("%d",&data);
		start = insert(start, data);
	}
	return start;
}

struct node *insert(struct node *start, int data)
{
	struct node *p, *temp;
	
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	/* List is empty or data is to be inserted */
	if(start == NULL || data < start->info)		
	{
		/* Insert elements in list in sorted order */
		temp->link = start;				
		start = temp;
		return start;
	}
	else
	{
		p = start;
		/* Insert elements in list in sorted order */
		while(p->link != NULL && p->link->info < data)
		{
			p = p->link;
		}
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

void display(struct node *start)
{
	struct node *p;
		
	if(start == NULL)
	{
		printf("\nList is Empty!!");
		return;
	}
	else
	{
		p = start;
		while(p != NULL)
		{
			printf("%d ",p->info);
			p = p->link;
		}
	}
	printf("\n");
}
