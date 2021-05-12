#include<stdio.h>
#include<stdlib.h>

struct node
{
	float fCoeff;
	int iExp;
	struct node *link;
};

struct node *CreateList(struct node *, int);
struct node *insert(struct node *, float, int);
struct node *AddPoly(struct node *, struct node *);
struct node *MultPoly(struct node *, struct node *);
void display(struct node *start);

void main()
{
	struct node *startPoly1 = NULL, *startPoly2 = NULL;
	struct node *resultPoly = NULL;
	int iChoice,n;
	
	printf("\nEnter no. of terms in 1st Polynomial: ");
	scanf("%d",&n);
	startPoly1 = CreateList(startPoly1, n);
	
	printf("\nEnter no. of terms in 2nd Polynomial: ");
	scanf("%d",&n);
	startPoly2 = CreateList(startPoly2, n);
	
	printf("\n1st Polynomial: ");
	display(startPoly1);
	
	printf("\n2nd Polynomial: ");
	display(startPoly2);
	
	while(1)
	{
		printf("\n\n1) ADD\n2) MULTIPLY\n3) Quit");
		printf("\nEnter your choice: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:	resultPoly = AddPoly(startPoly1,startPoly2);
					printf("After addition polynomial is: ");
					display(resultPoly);
					break;
			case 2:	resultPoly = MultPoly(startPoly1,startPoly2);
					printf("After addition polynomial is: ");
					display(resultPoly);
					break;
					
			case 3: exit(1);
		}
	}
}

struct node *CreateList(struct node *start, int n)
{
	int i,iEx;
	float fCof;
	
	for(i = 1; i <= n; ++i)
	{
		printf("Enter coeficient for term %d: ",i);
		scanf("%f",&fCof);
		printf("Enter Exponent for term %d: ",i);
		scanf("%d",&iEx);
		
		start = insert(start,fCof,iEx);
		if(start == NULL)
		{
			printf("\nWarning!! NOT ENOUGH MEMORY\n\tFree some space");
			exit(1);
		}
	}
	return start;
}

struct node *insert(struct node *start, float fCof,int iEx)
{
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	/* Very important to check if the pointer returned by malloc in not NULL   */
	/* If the pointer returned is NULL then there is not enough memory in heap */
	if(temp != NULL)
	{	
		temp->fCoeff = fCof;
		temp->iExp = iEx;
		
		/* Inserting terms in descending order will help in adding 2 polynomials */
		if(start == NULL || iEx > start->iExp)
		{
			temp->link = start;
			start = temp;
		}		
		else
		{
			p = start;
			while(p->link != NULL && p->link->iExp >= iEx)
			{
				p = p->link;	
			}
			temp->link = p->link;
			p->link = temp;
		}
	}
	else
	{
		return NULL;
	}
	return start;
}

struct node *AddPoly(struct node *p1, struct node *p2)
{
	struct node *resultPoly = NULL;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->iExp > p2->iExp)
		{
			resultPoly = insert(resultPoly, p1->fCoeff, p1->iExp);
			p1 = p1->link;
		}
		else if(p2->iExp > p1->iExp)
		{
			resultPoly = insert(resultPoly, p2->fCoeff, p2->iExp);
			p2 = p2->link;
		}
		else if(p1->iExp == p2->iExp)
		{
			resultPoly = insert(resultPoly, p1->fCoeff + p2->fCoeff, p1->iExp);
			p2 = p2->link;
			p1 = p1->link;
		}
	}
	
	/* If poly2 is finished insert terms left in poly1 */
	while(p1 != NULL)
	{
		resultPoly = insert(resultPoly, p1->fCoeff, p1->iExp);
		p1 = p1->link;
	}
	
	/* If poly1 is finished insert terms left in poly2*/
	while(p2 != NULL)
	{
		resultPoly = insert(resultPoly, p2->fCoeff, p2->iExp);
		p2 = p2->link;
	}
	
	return resultPoly;
}

struct node *MultPoly(struct node *p1, struct node *p2)
{
	struct node *resultPoly = NULL;

	if(p1 == NULL || p2 == NULL)
	{
		printf("\nMultiplied polynomial is zero polunomial");
		return NULL;
	}
	
	while(p1 != NULL)
	{
		while(p2 != NULL)
		{
			resultPoly = insert(resultPoly, (p1->fCoeff * p2->fCoeff), (p1->iExp + p2->iExp));
			p2=p2->link;
		}
		p1=p1->link;
	}
	return resultPoly;
}

void display(struct node *start)
{
	struct node *p;
		
	if(start == NULL)
	{
		printf("\nNo polynomial in memory!!");
		return;
	}
	else
	{
		p = start;
		while(p != NULL)
		{
			printf("(%.1fx^%d)",p->fCoeff,p->iExp);
			p = p->link;
		}
	}
	printf("\n");
}
