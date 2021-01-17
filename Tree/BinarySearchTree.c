/*
*	The Binary Tree is Traversed using the Recursive method.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int iInfo;
	struct node *right;
}*root=NULL;

void CreateBST(int);
void PreorderTraversal(struct node*);
void InorderTraversal(struct node*);
void PostorderTraversal(struct node*);

int main()
{
	int iChoice, iNodeCnt, iData;
	int i;
	
	while(1)
	{
		printf("\n\n1) Create Tree\n2) Traverse Using Preorder");
		printf("\n3) Traverse Using Inorder\n4) Traverse Using Postorder\n5) Exit\nChoice: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1: printf("Enter Number of Nodes: ");
					scanf("%d",&iNodeCnt);
					printf("Enter the elements: ");
					for(i = 0; i < iNodeCnt; ++i)
					{
						scanf("%d",&iData);
						CreateBST(iData);
					}
					break;
			case 2: PreorderTraversal(root);
					printf("\n");
					break;
			case 3: InorderTraversal(root);
					printf("\n");
					break;		
			case 4: PostorderTraversal(root);
					printf("\n");
					break;				
			case 5: exit(1);
				
			default: printf("\nWrong Choice!! Please enter correct option");
		}
	}
	return 0;
}

void CreateBST(int iData)
{
	struct node *temp, *ptr;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->iInfo = iData;
	temp->left = NULL;
	temp->right = NULL;
	
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		ptr = root;
		while(ptr != NULL)
		{
			if(iData < ptr->iInfo)
			{
				if(ptr->left == NULL)
				{
					ptr->left = temp;
					return;
				}	
				else
					ptr = ptr->left;
			}
			else
			{
				if(ptr->right == NULL)
				{
					ptr->right = temp;
					return;
				}
				else
					ptr = ptr->right;
			}
		}
	}
}

void PreorderTraversal(struct node *ptr)
{
	if(ptr != NULL)
	{
		printf("%d  ",ptr->iInfo);
		PreorderTraversal(ptr->left);
		PreorderTraversal(ptr->right);
	}
}

void InorderTraversal(struct node *ptr)
{
	if(ptr != NULL)
	{
		PreorderTraversal(ptr->left);
		printf("%d  ", ptr->iInfo);
		PreorderTraversal(ptr->right);
	}
}

void PostorderTraversal(struct node *ptr)
{
	if(ptr != NULL)
	{
		PreorderTraversal(ptr->left);
		PreorderTraversal(ptr->right);
		printf("%d  ",ptr->iInfo);
	}
}
