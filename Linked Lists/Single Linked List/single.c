#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
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

