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

