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
					CreateList(m);		
				}
				break;

			case 2:	printf("\nEnter The Element To Add:-->");
				scanf("%d",&m);
				AddAtBeg(m);		
				break;

			case 3:	printf("\nEnter The Element To Add and Position:-->");
				scanf("%d %d",&m,&p);
				InsertAt(m,p);	
				break;

			case 4:	printf("\nEnter element to delete:-->");
				scanf("%d",&m);

				del(m);	
				break;

			case 5:	display();	
				break;
			
			case 6: count();	
				break;

			case 7: reverse();	
				break;

			case 8: exit(1);
				break;

			default: printf("WRONG OPTION!! Please choose correct option\n");
				
		}
	}
}

