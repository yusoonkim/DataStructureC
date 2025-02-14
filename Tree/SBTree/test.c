#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct SimpleBinaryTree
{
	struct SimpleBinaryTree *Left;
	struct SimpleBinaryTree *Right;
	DataType Data;
} SBTNode;

SBTNode	*CreateNode(DataType data)
{
	SBTNode	*node = (SBTNode*)malloc(sizeof(SBTNode));
	node->Left = NULL;
	node->Right = NULL;
	node->Data = data;
	return (node);
}

void	DestroyNode(SBTNode *node)
{
	free(node);
}

void	DestroyTree(SBTNode *root)
{
	if (root == NULL)
		return ;
	DestroyTree(root->Left);
	DestroyTree(root->Right);
	DestroyNode(root);
}

void	PreorderPrint(SBTNode *root)
{
	if (root == NULL)
		return ;
	printf(" %c", root->Data);
	PreorderPrint(root->Left);
	PreorderPrint(root->Right);
}

void	InorderPrint(SBTNode *root)
{
	if (root == NULL)
		return ;
	InorderPrint(root->Left);
	printf(" %c", root->Data);
	InorderPrint(root->Right);
}

void	PostorderPrint(SBTNode *root)
{
	if (root == NULL)
		return ;
	PostorderPrint(root->Left);
	PostorderPrint(root->Right);
	printf(" %c", root->Data);
}

int	main()
{
	SBTNode	*A = CreateNode('A');
	SBTNode	*B = CreateNode('B');
	SBTNode	*C = CreateNode('C');
	SBTNode	*D = CreateNode('D');
	SBTNode	*E = CreateNode('E');
	SBTNode	*F = CreateNode('F');
	SBTNode	*G = CreateNode('G');
	A->Left = B;
	B->Left = D;
	A->Right = C;
	C->Left = E;
	C->Right = F;
	F->Right = G;
	printf("Preorder :");
	PreorderPrint(A);
	printf("\n\nInorder : ");
	InorderPrint(A);
	printf("\n\nPostorder : ");
	PostorderPrint(A);
	printf("\n\n");
	DestroyTree(A);
	return (0);
}