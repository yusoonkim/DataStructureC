#ifndef DLL_H
#define DLL_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	struct node *PrevNode;
	struct node *NextNode;
	int	Data;
} node;

node *CreateNode(int data);
void AppendNode(node **list, node *new);
void InsertAfter(node *prev, node *new);
void DestroyNode(node *remove);
void RemoveNode(node **list, node *remove);
node *GetNodeAt(node *list, int count);
int CountNode(node *list);
void PrintNode(node *list);

#endif
