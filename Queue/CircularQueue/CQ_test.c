#include "CQ.h"

int	main()
{
	Queue	*queue;
	CreateQueue(&queue, 5);
	int	i = 0;
	while (i < 5)
	{
		Enqueue(queue, i);
		i++;
	}
	PrintNodes(queue);
	printf("GetSize : %d, IsFull : %d\n",GetSize(queue), IsFull(queue));
	while (!IsEmpty(queue))
		Dequeue(queue);
	printf("GetSize : %d, IsEmpty : %d\n",GetSize(queue), IsEmpty(queue));
	PrintNodes(queue);
	DestroyQueue(queue);
	return (0);
}
