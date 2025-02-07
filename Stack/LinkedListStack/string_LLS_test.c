#include "string_LLS.h"

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
