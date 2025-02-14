#ifndef LCRS_H
#define LCRS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *LeftChild;
	struct Node	*RightSibling;
	char	Data;
} Node;

Node	*CreateNode(char data);
void	DestroyNode(Node *node);
void	DestroyTree(Node *root);
void	AddChildNode(Node *parent, Node *child);
void	PrintTree(Node *root, int dep);
int	CountNodes(Node *root);
int	CountLeafs(Node *root);

#endif
