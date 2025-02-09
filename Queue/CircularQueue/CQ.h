#ifndef CQ_H
#define CQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int	Data;
} Node;

typedef struct Queue
{
	int	Front;
	int	Rear;
	int	Capacity;
	Node	*Nodes;
} Queue;

void	CreateQueue(Queue **queue, int cap);
void	DestroyQueue(Queue *queue);
void	PrintNodes(Queue *queue);
void	Enqueue(Queue *queue, int data);
int	Dequeue(Queue *queue);
int	GetSize(Queue *queue);
int	IsFull(Queue *queue);
int	IsEmpty(Queue *queue);

#endif
