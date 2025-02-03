#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node	*NextNode;
	struct node	*PrevNode;
	int	Data;
} node;

node *CreateNode(int data)
{
	node *new;
    
	new = (node*)malloc(sizeof(node));
	new->PrevNode = NULL;
	new->NextNode = NULL;
	new->Data = data;
	return (new);
}

void DestroyNode(node *destroy)
{
	free(destroy);
}

void AppendNode(node **list, node *new)
{
	if (*list == NULL)
	{
		*list = new;
		new->PrevNode = new;
		new->NextNode = new;
	}
	else
	{
		new->PrevNode = (*list)->PrevNode;
		new->NextNode = *list;
		(*list)->PrevNode = new;
		new->PrevNode->NextNode = new;
	}
}

void InsertAfter(node *prev, node *new)
{
	new->NextNode = prev->NextNode;
	new->PrevNode = prev;
	prev->NextNode->PrevNode = new;
	prev->NextNode = new;
}

void RemoveNode(node **list, node *remove)
{
	if (*list == remove && (*list)->NextNode == remove)
			*list = NULL;
	else
	{
		remove->NextNode->PrevNode = remove->PrevNode;
		remove->PrevNode->NextNode = remove->NextNode;
		if (*list == remove)
			*list = remove->NextNode;
	}
	remove->NextNode = NULL;
	remove->PrevNode = NULL;
	DestroyNode(remove);
}

node *GetNodeAt(node *list, int count)
{
	while (count > 0)
	{
		list = list->NextNode;
		count--;
	}
	return (list);
}

int GetNodeCount(node *list)
{
	int	i;
	node *head;

	head = list;
	i = 0;
	if (list == NULL)
		return (0);
	while (1)
	{
		list = list->NextNode;
		i++;
		if (list == head)
			break;
	}
	return (i);
}

void PrintList(node *list)
{
	node *head;

	head = list;
	if (list == NULL)
		return;
	else
		printf("%d ", list->Data);
	list = list->NextNode;
	while (list != head)
	{
		printf("%d ", list->Data);
		list = list->NextNode;
	}
	printf("\n");
}

void PrintNode(node *node)
{
	if (node->NextNode == node || node->NextNode == NULL)
	{
		printf("Prev : NULL\n");
		printf("Current : %d\n", node->Data);
		printf("Next : NULL\n");
	}
	else
	{
		printf("Prev : %d\n", node->PrevNode->Data);
		printf("Current : %d\n", node->Data);
		printf("Next : %d\n", node->NextNode->Data);
	}
}

int	main()
{
	node *List;

	List = NULL;
	AppendNode(&List, CreateNode(11));
	AppendNode(&List, CreateNode(22));
	AppendNode(&List, CreateNode(44));
	PrintList(List);
	InsertAfter(GetNodeAt(List, 1), CreateNode(33));
	PrintList(List);
	RemoveNode(&List, GetNodeAt(List, 3));
	PrintList(List);
	printf("count = %d\n", GetNodeCount(List));
	printf("___ about 22 node ___\n");
	PrintNode(GetNodeAt(List, 1));
	return (0);
}