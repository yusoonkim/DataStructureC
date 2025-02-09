#ifndef LQ_H
#define LQ_H

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

void	CreateQueue(Queue **queue);
void	DestroyQueue(Queue *queue);
Node	*CreateNode(char *data);
void	DestroyNode(Node *node);
void	Enqueue(Queue *queue, Node *node);
Node	*Dequeue(Queue *queue);
int	IsEmpty(Queue *queue);
void	PrintNodes(Queue *queue);


#endif
