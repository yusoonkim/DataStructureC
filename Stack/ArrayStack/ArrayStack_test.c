#include "ArrayStack.h"

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
