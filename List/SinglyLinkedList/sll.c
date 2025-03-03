#include <stdio.h>
#include <stdlib.h>

typedef struct hi
{
	struct hi *NextNode;
	int	Data;
}Node;

Node *SLL_CreateNode(int data)
{
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	node -> Data = data;
	node -> NextNode = NULL;
	return (node);
}

void SLL_DestroyNode(Node *node)
{
	free(node);
}

void SLL_AppendNode(Node **Head, Node *new)
{
	if (*Head == NULL)
		*Head = new;
	else
	{
		Node *HeadToTail = *Head;
		while (HeadToTail->NextNode != NULL)
			HeadToTail = HeadToTail->NextNode;
		HeadToTail->NextNode = new;
	}
}

Node *SLL_GetNodeAt(Node *list, int count)
{
	while (0 < count-- && list != NULL)
		list = list->NextNode;
	return (list);
}

void SLL_RemoveNode(Node **list, Node *node)
{
	if (*list == node)
		*list = (*list)->NextNode;
	else
	{
		Node *FrontNode = *list;
		while (FrontNode != NULL && FrontNode->NextNode != node)
			FrontNode = FrontNode->NextNode;
		if (FrontNode != NULL)
			FrontNode->NextNode = node->NextNode;
	}
	SLL_DestroyNode(node);
}

void SLL_InsertNode(Node *FrontNode, Node *node)
{
	node->NextNode = FrontNode->NextNode;
	FrontNode->NextNode = node;
}

int	SLL_CountNode(Node *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->Node;
		i++;
	}
	return (i);
}
