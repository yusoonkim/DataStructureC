#include "CQ.h"

void	CreateQueue(Queue **queue, int cap)
{
	*queue = (Queue*)malloc(sizeof(Queue));

	(*queue)->Nodes = (Node*)malloc((cap + 1) * sizeof(Node));
	(*queue)->Front = 0;
	(*queue)->Rear = 0;
	(*queue)->Capacity = cap;
}

void	DestroyQueue(Queue *queue)
{
	free(queue->Nodes);
	free(queue);
}

void	PrintNodes(Queue *queue)
{
	int	front = queue->Front;
	int	rear = queue->Rear;
	printf("PrintNodes : ");
	if (front == rear)
	{
		printf("Nothing In Queue\n");
		return ;
	}
	while (front < rear - 1)
	{
			printf("%d, ", queue->Nodes[front].Data);
			front++;
	}
	printf("%d\n", queue->Nodes[rear - 1].Data);
}

void	Enqueue(Queue *queue, int data)
{
	int	EnqIndex = queue->Rear;

	if (queue->Rear == queue->Capacity)
		queue->Rear = 0;
	else
		queue->Rear++;

	queue->Nodes[EnqIndex].Data = data;
}

int	Dequeue(Queue *queue)
{
	int	DeqIndex = queue->Front;

	if (queue->Front == queue->Capacity)
		queue->Front = 0;
	else
		queue->Front++;

	return (queue->Nodes[DeqIndex].Data);
}

int	GetSize(Queue *queue)
{
	if (queue->Rear == queue->Front)
		return (0);
	else if (queue->Rear > queue->Front)
		return (queue->Rear - queue->Front);
	else
		return (queue->Capacity - queue->Front + queue->Rear + 1);
}

int	IsFull(Queue *queue)
{
	if (queue->Rear > queue->Front)
		return (queue->Rear - queue->Front == queue->Capacity);
	else
		return (queue->Front - queue->Rear == 1);
}

int	IsEmpty(Queue *queue)
{
	return (queue->Front == queue->Rear);
}
