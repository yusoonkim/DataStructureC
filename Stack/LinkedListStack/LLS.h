#ifndef LLS_H
#define LLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char	*Data;
	struct Node	*NextNode;
} Node;

typedef struct Stack
{
	Node	*List;
	Node	*Top;
} Stack;

void	CreateStack(Stack **stack);
Node	*CreateNode(char *data);
void	Push(Stack *stack, Node *node);
Node	*Pop(Stack *stack);
void	DestroyNode(Node *destroy);
int	IsEmpty(Stack *stack);
void	DestroyStack(Stack *stack);
int	GetSize(Stack *stack);
Node	*Top(Stack *stack);

#endif