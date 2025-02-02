#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	struct node *PrevNode;
	struct node *NextNode;
	int	Data;
} node;

node *CreateNode(int data)
{
	node *NewNode;

	NewNode = (node*)malloc(sizeof(node));
	NewNode->Data = data;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;
	return (NewNode);
}

void AppendNode(node **list, node *new)
{
	node *tail;

	if (*list == NULL)
		*list = new;
	else
	{
		tail = *list;
		while (tail->NextNode != NULL)
			tail = tail->NextNode;
		tail->NextNode = new;
		new->PrevNode = tail;
	}
}

void InsertAfter(node *prev, node *new)
{
	new->PrevNode = prev;
	new->NextNode = prev->NextNode;
	prev->NextNode = new;
	if (new->NextNode != NULL)
		new->NextNode->PrevNode = new;
}

void DestroyNode(node *remove)
{
	free(remove);
}

void RemoveNode(node **list, node *remove)
{
	if (*list == remove)
	{
		*list = remove->NextNode;
		if (remove->NextNode != NULL)
			remove->NextNode->PrevNode = NULL;
	}
	else
	{
		remove->PrevNode->NextNode = remove->NextNode;
		if (remove->NextNode != NULL)
			remove->NextNode->PrevNode = remove->PrevNode;
	}
	remove->PrevNode = NULL;
	remove->NextNode = NULL;
	DestroyNode(remove);
}

node *GetNodeAt(node *list, int count)
{
	while (count-- > 0 && list != NULL)
		list = list->NextNode;
	return (list);
}

int CountNode(node *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->NextNode;
		i++;
	}
	return (i);
}

void PrintNode(node *list)
{
	while (list != NULL)
	{
		printf("%d ", list->Data);
		list=list->NextNode;
	}
	printf("\n");
}

int	main()
{
	node *List = NULL;
	AppendNode(&List, CreateNode(100));
	AppendNode(&List, CreateNode(200));
	AppendNode(&List, CreateNode(400));
	PrintNode(List);
	InsertAfter(GetNodeAt(List, 1), CreateNode(300));
	PrintNode(List);
	RemoveNode(&List, GetNodeAt(List, 1));
	RemoveNode(&List, GetNodeAt(List, 1));
	PrintNode(List);
	InsertAfter(GetNodeAt(List, 0), CreateNode(500));
	PrintNode(List);
	printf("count = %d", CountNode(List));
	return (0);
}


