/*
*	Here the Binary Tree is traversed using Recursive method
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int iInfo;
	struct node *right;
}*root=NULL;

void InsertInBST(int);
void Mirror(struct node*);
void PreorderTraversal(struct node*);
void InorderTraversal(struct node*);
void PostorderTraversal(struct node*);
void LevelOrderTraversal(struct node* ptr);
void PrintGivenLevel(struct node* ptr, int level);
int  GetHeightOfTree(struct node*);

int main()
{
	int iChoice, iNodeCnt, iData;
	int i;
	
	while(1)
	{
		printf("\n\n1) Create Tree\n2) Traverse Using Preorder");
		printf("\n3) Traverse Using Inorder\n4) Traverse Using Postorder\n5) Level Order Traversal\n6) Get Height Of Tree\n7) Mirror\n8) Exit\nChoice: ");
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1: printf("Enter Number of Nodes: ");
					scanf("%d",&iNodeCnt);
					printf("Enter the elements: ");
					for(i = 0; i < iNodeCnt; ++i)
					{
						scanf("%d",&iData);
						InsertInBST(iData);
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
			case 5: LevelOrderTraversal(root);
					printf("\n");
					break;
			case 6: printf("Height is: %d\n",GetHeightOfTree(root));
					break;
			case 7: Mirror(root);	
					break;				
			case 8: exit(1);
				
			default: printf("\nWrong Choice!! Please enter correct option");
		}
	}
	return 0;
}

void InsertInBST(int iData)
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


void Mirror(struct node* node) 
{
    if (node == NULL) 
    { 
       return; 
    }
    else
    {
        struct node* temp;
          
        /* do the subtrees */
        Mirror(node->left);
        Mirror(node->right);
      
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void PreorderTraversal(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	printf("%d  ",ptr->iInfo);
	PreorderTraversal(ptr->left);
	PreorderTraversal(ptr->right);
}

void InorderTraversal(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	InorderTraversal(ptr->left);
	printf("%d  ", ptr->iInfo);
	InorderTraversal(ptr->right);
}

void PostorderTraversal(struct node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	PostorderTraversal(ptr->left);
	PostorderTraversal(ptr->right);
	printf("%d  ",ptr->iInfo);
}

void LevelOrderTraversal(struct node* ptr)
{
    int iHeight = GetHeightOfTree(root);
    int i;
    for (i = 1; i <= iHeight; i++)
    {
        PrintGivenLevel(ptr, i);
    }
}
 
/* Print nodes at a given level */
void PrintGivenLevel(struct node* ptr, int iLevel)
{
	/* Base Case */
    if (ptr == NULL)
    {
        return;
    }
    if (iLevel == 1)
    {
        printf("%d ",ptr->iInfo);
    }
    else if (iLevel > 1)
    {
        PrintGivenLevel(ptr->left, iLevel - 1);
        PrintGivenLevel(ptr->right, iLevel - 1);
    }
}

int GetHeightOfTree(struct node *root)
{
	int iLeftHeight, iRightHeight;
	
	/* Base Case */
	if(root == NULL)
		return 0;
		
	iLeftHeight = GetHeightOfTree(root->left);
	iRightHeight = GetHeightOfTree(root->right);
	
	if(iLeftHeight > iRightHeight)
		return 1 + iLeftHeight;
	else
		return 1 + iRightHeight;		
}
