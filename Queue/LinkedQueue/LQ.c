#include "LQ.h"

void	CreateQueue(Queue **queue)
{
	*queue = (Queue*)malloc(sizeof(Queue));
	(*queue)->Front = NULL;
	(*queue)->Rear = NULL;
	(*queue)->Count = 0;
}

void	DestroyQueue(Queue *queue)
{
	Node	*deq;
	while (!IsEmpty(queue))
	{
		deq = Dequeue(queue);
		DestroyNode(deq);
	}
	free(queue);
}

Node	*CreateNode(char *data)
{
	Node	*node = (Node*)malloc(sizeof(Node));
	node->Data = (char*)malloc(strlen(data) + 1);
	strcpy(node->Data, data);
	node->NextNode = NULL;
	return (node);
}

void	DestroyNode(Node *node)
{
	free(node->Data);
	free(node);
}

void	Enqueue(Queue *queue, Node *node)
{
	if (queue->Front == NULL)
	{
		queue->Front = node;
		queue->Rear = node;
		queue->Count++;
	}
	else
	{
		queue->Rear->NextNode = node;
		queue->Rear = node;
		queue->Count++;
	}
}

Node	*Dequeue(Queue *queue)
{
	Node	*deq = queue->Front;
	if (queue->Count == 0)
		return (0);
	else if (queue->Count == 1)
	{
		queue->Front = NULL;
		queue->Rear = NULL;
		queue->Count--;
	}
	else
	{
		queue->Front = deq->NextNode;
		queue->Count--;
	}
	return (deq);
}

int	IsEmpty(Queue *queue)
{
	return (queue->Front == NULL);
}

void	PrintNodes(Queue *queue)
{
	Node	*Front = queue->Front;
	printf("PrintNodes : ");
	while (Front != NULL)
	{
		if (Front->NextNode == NULL)
			break ;
		printf("%s, ", Front->Data);
		Front = Front->NextNode;
	}
	if (Front != NULL)
		printf("%s\n", Front->Data);
	else
		printf("**Nothing In Queue**\n");
}

