#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int	Data;
} Node;

typedef struct ArrayStack
{
	int	Capacity;
	int	Top;
	Node	*Nodes;
} ArrayStack;

void	CreateStack(ArrayStack **stack, int cap);
void	DestroyStack(ArrayStack *stack);
void	Push(ArrayStack *stack, int data);
int	Pop(ArrayStack *stack);
int	Top(ArrayStack *stack);
int	GetSize(ArrayStack *stack);
int	IsEmpty(ArrayStack *stack);
void	PrintNodes(ArrayStack *stack);

#endif
