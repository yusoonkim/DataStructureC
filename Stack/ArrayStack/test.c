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

void	CreateStack(ArrayStack **stack, int cap)
{
	*stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*stack)->Nodes = (Node*)malloc(cap * sizeof(Node));
	(*stack)->Capacity = cap;
	(*stack)->Top = -1;
}

void	DestroyStack(ArrayStack *stack)
{
	free(stack->Nodes);
	free(stack);
}

void	Push(ArrayStack *stack, int data)
{
	stack->Top++;
	stack->Nodes[stack->Top].Data = data;
}

int	Pop(ArrayStack *stack)
{
	int	i = stack->Top--;
	return (stack->Nodes[i].Data);
}

int	Top(ArrayStack *stack)
{
	return (stack->Nodes[stack->Top].Data);
}

int	GetSize(ArrayStack *stack)
{
	return (stack->Top + 1);
}

int	IsEmpty(ArrayStack *stack)
{
	return (stack->Top == -1);
}

void	PrintNodes(ArrayStack *stack)
{
	int	i = 0;
	int	j = stack->Top;

	while (i <= j)
	{
		printf("%d ", stack->Nodes[i].Data);
		i++;
	}
	printf("\n");
}

int	main()
{
	int	i = 1;
	ArrayStack *stack = NULL;
	CreateStack(&stack, 10);
	printf("FirstTop = %d\n", stack->Top);
	while (i <= 10)
	{
		Push(stack, i);
		i++;
	}
	PrintNodes(stack);
	i = 0;
	while (i < 3)
	{
		printf("%d ", Pop(stack));
		i++;
	}
	printf("\n");
	PrintNodes(stack);
	printf("GetSize = %d\n", GetSize(stack));
	Pop(stack);
	printf("%d\n", Top(stack));
	i = 0;
	while (i < 6)
	{
		Pop(stack);
		i++;
	}
	printf("IsEmpty = %d", IsEmpty(stack));
	DestroyStack(stack);
	return (0);
}
