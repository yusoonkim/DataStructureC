#ifndef CDLL_H
#define CDLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node	*NextNode;
	struct node	*PrevNode;
	int	Data;
} node;

node *CreateNode(int data);
void DestroyNode(node *destroy);
void AppendNode(node **list, node *new);
void InsertAfter(node *prev, node *new);
void RemoveNode(node **list, node *remove);
node *GetNodeAt(node *list, int count);
int GetNodeCount(node *list);
void PrintList(node *list);
void PrintNode(node *node);

#endif
