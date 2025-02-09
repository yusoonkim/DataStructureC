#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	struct Node	*NextNode;
	char	*Data;
} Node;

typedef struct LinkedQueue
{
	Node	*Front;
	Node	*Rear;
	int	Count;
} Queue;

void	CreateQueue(Queue **queue)
{
	*queue = (Queue*)malloc(sizeof(Queue));
	(*queue)->Front = NULL;
	(*queue)->Rear = NULL;
	(*queue)->Count = 0;
}


void	DestroyNode(Node *node)
{
	free(node->Data);
	free(node);
}

int	IsEmpty(Queue *queue)
{
	return (queue->Front == NULL);
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