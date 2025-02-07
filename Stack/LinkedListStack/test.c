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

void	CreateStack(LinkedListStack **Stack)
{
	*Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

Node	*CreateNode(char *data)
{
	Node	*NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(data) + 1);
	strcpy(NewNode->Data, data);
	NewNode->NextNode = NULL;
	return (NewNode);
}

void	Push(LinkedListStack *Stack, Node *node)
{
	if (Stack->Top == NULL)
		Stack->List = node;
	else
		Stack->Top->NextNode = node;
	Stack->Top = node;
}

Node	*Pop(LinkedListStack *Stack)
{
	Node	*popped = Stack->Top;
	if (Stack->List == popped)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node	*HeadToPrev = Stack->List;
		while (HeadToPrev->NextNode != popped && HeadToPrev != popped)
			HeadToPrev = HeadToPrev->NextNode;
		Stack->Top = HeadToPrev;
		Stack->Top->NextNode = NULL;
	}
	return (popped);
}

void	DestroyNode(Node *destroy)
{
	free(destroy->Data);
	free(destroy);
}

int	IsEmpty(LinkedListStack *Stack)
{
	return (Stack->List == NULL);
}

void	DestroyStack(LinkedListStack *Stack)
{
	Node	*destroy;
	while(!IsEmpty(Stack))
	{
		destroy = Pop(Stack);
		DestroyNode(destroy);
	}
	free(Stack);
}

int	GetSize(LinkedListStack *Stack)
{
	int	count = 0;
	Node	*head = Stack->List;
	while (head != NULL)
	{
		head = head->NextNode;
		count++;
	}
	return (count);
}

Node	*Top(LinkedListStack *Stack)
{
	return (Stack->Top);
}

int	main()
{
	LinkedListStack	*Stack;
	Node	*Popped;
	CreateStack(&Stack);
	Push(Stack, CreateNode("abc"));
	Push(Stack, CreateNode("def"));
	Push(Stack, CreateNode("efg"));
	Push(Stack, CreateNode("hij"));
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
