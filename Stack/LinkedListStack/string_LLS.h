#ifndef STRING_LLS_H
#define STRING_LLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char	*Data;
	struct Node	*NextNode;
} Node;

typedef struct LinkedListStack
{
	Node	*List;
	Node	*Top;
} LinkedListStack;

void	CreateStack(LinkedListStack **Stack);
Node	*CreateNode(char *data);
void	Push(LinkedListStack *Stack, Node *node);
Node	*Pop(LinkedListStack *Stack);
void	DestroyNode(Node *destroy);
int	IsEmpty(LinkedListStack *Stack);
void	DestroyStack(LinkedListStack *Stack);
int	GetSize(LinkedListStack *Stack);
Node	*Top(LinkedListStack *Stack);

#endif