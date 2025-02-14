#include "LCRS.h"

Node	*CreateNode(char data)
{
	Node	*node = (Node*)malloc(sizeof(Node));
	node->LeftChild = NULL;
	node->RightSibling = NULL;
	node->Data = data;
	return (node);
}

void	DestroyNode(Node *node)
{
	free(node);
}

void	DestroyTree(Node *root)
{
	if (root->LeftChild != NULL)
		DestroyTree(root->LeftChild);
	if (root->RightSibling != NULL)
		DestroyTree(root->RightSibling);
	root->LeftChild = NULL;
	root->RightSibling = NULL;
	DestroyNode(root);
}

void	AddChildNode(Node *parent, Node *child)
{
	Node	*LastChild;
	if (parent->LeftChild == NULL)
		parent->LeftChild = child;
	else
	{
		LastChild = parent->LeftChild;
		while (LastChild->RightSibling != NULL)
			LastChild = LastChild->RightSibling;
		LastChild->RightSibling = child;
	}
}

void	PrintTree(Node *root, int dep)
{
	int	i = dep;
	while (i > 1)
	{
		printf("	");
		i--;
	}
	if (dep != 0)
		printf("+--");
	printf("%c\n", root->Data);
	if (root->LeftChild != NULL)
		PrintTree(root->LeftChild, dep + 1);
	if (root->RightSibling != NULL)
		PrintTree(root->RightSibling, dep);
}

int	CountNodes(Node *root)
{
	int	i = 1;
	if (root->LeftChild)
		i += CountNodes(root->LeftChild);
	if (root->RightSibling)
		i += CountNodes(root->RightSibling);
	return (i);
}

int	CountLeafs(Node *root)
{
	int	i = 0;
	if (root->LeftChild)
		i += CountLeafs(root->LeftChild);
	else
		i++;
	if (root->RightSibling)
		i += CountLeafs(root->RightSibling);
	return (i);
}