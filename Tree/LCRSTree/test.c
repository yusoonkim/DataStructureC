#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *LeftChild;
	struct Node	*RightSibling;
	char	Data;
} Node;

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

int	main()
{
	Node	*root = CreateNode('A');
	Node	*B = CreateNode('B');
	Node	*C = CreateNode('C');
	Node	*D = CreateNode('D');
	Node	*E = CreateNode('E');
	Node	*F = CreateNode('F');
	Node	*G = CreateNode('G');
	AddChildNode(root, B);
	AddChildNode(root, E);
	AddChildNode(root, G);
	AddChildNode(B, C);
	AddChildNode(C, D);
	AddChildNode(E, F);
	PrintTree(root, 0);
	DestroyTree(root);
}
