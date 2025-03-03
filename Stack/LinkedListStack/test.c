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

void	CreateStack(Stack **stack)
{
	*stack = (Stack*)malloc(sizeof(Stack));
	(*stack)->List = NULL;
	(*stack)->Top = NULL;
}

Node	*CreateNode(char *data)
{
	Node	*new = (Node*)malloc(sizeof(Node));
	char	*str = (char*)malloc(strlen(data) + 1);
	strcpy(str, data);
	new->Data = str;
	new->NextNode = NULL;
	return (new);
}

void	Push(Stack *stack, Node *node)
{
	if (stack->List == NULL)
		stack->List = node;
	else
		stack->Top->NextNode = node;
	stack->Top = node;
}

Node	*Pop(Stack *stack)
{
	Node	*popped = stack->Top;
	if (popped == stack->List)
	{
		stack->Top = NULL;
		stack->List = NULL;
	}
	else
	{
		Node	*PrevTop = stack->List;
		while (PrevTop->NextNode != stack->Top)
			PrevTop = PrevTop->NextNode;
		stack->Top = PrevTop;
		PrevTop->NextNode = NULL;
	}
	return (popped);
}

void	DestroyNode(Node *destroy)
{
	free(destroy->Data);
	free(destroy);
}

int	IsEmpty(Stack *stack)
{
	return (stack->List == NULL);
}

void	DestroyStack(Stack *stack)
{
	Node	*popped;
	while (!IsEmpty(stack))
	{
		popped = Pop(stack);
		DestroyNode(popped);
	}
	free(stack);
}

int	GetSize(Stack *stack)
{
	int	count = 0;
	Node	*head = stack->List;
	while (head != NULL)
	{
		head = head->NextNode;
		count++;
	}
	return (count);
}

Node	*Top(Stack *stack)
{
	return (stack->Top);
}

int	main()
{
	Stack	*Stack;
	Node	*Popped;
	CreateStack(&Stack);
	Push(Stack, CreateNode("abc"));
	Push(Stack, CreateNode("def"));
	Push(Stack, CreateNode("ghi"));
	Push(Stack, CreateNode("jkl"));
	printf("Size : %d, Top : %s\n", GetSize(Stack), Top(Stack)->Data);
	while (!IsEmpty(Stack))
	{
		Popped = Pop(Stack);
		printf("Popped : %s, ", Popped->Data);
		DestroyNode(Popped);
		if (IsEmpty(Stack))
			printf("Stack is empty");
		else
			printf("Current Top : %s\n", Top(Stack)->Data);
	}
	DestroyStack(Stack);
	return (0);
}
