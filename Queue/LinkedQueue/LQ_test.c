#include "LQ.h"

int	main()
{
	Queue	*queue;
	CreateQueue(&queue);
	Enqueue(queue, CreateNode("Is"));
	Enqueue(queue, CreateNode("For"));
	Enqueue(queue, CreateNode("Test"));
	Enqueue(queue, CreateNode("From"));
	Enqueue(queue, CreateNode("Yuskim"));
	PrintNodes(queue);
	printf("NodesCount : %d, IsEmpty : %d\n", queue->Count, IsEmpty(queue));
	int	i = 0;
	Node	*deq;
	while (i < 5)
	{
		deq = Dequeue(queue);
		printf("Dequeue : %s\n", deq->Data);
		DestroyNode(deq);
		i++;
	}
	printf("NodesCount : %d, IsEmpty : %d\n", queue->Count, IsEmpty(queue));
	DestroyQueue(queue);
	return (0);
}
