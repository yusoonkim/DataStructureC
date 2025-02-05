#include "ArrayStack.h"

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


