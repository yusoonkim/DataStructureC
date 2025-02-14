#include "SBT.h"

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
