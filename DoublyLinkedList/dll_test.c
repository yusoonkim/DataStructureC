#include "dll.h"

int	main()
{
	node *List = NULL;
	AppendNode(&List, CreateNode(100));
	AppendNode(&List, CreateNode(200));
	AppendNode(&List, CreateNode(400));
	PrintList(List);
	InsertAfter(GetNodeAt(List, 1), CreateNode(300));
	PrintList(List);
	RemoveNode(&List, GetNodeAt(List, 1));
	RemoveNode(&List, GetNodeAt(List, 1));
	PrintList(List);
	InsertAfter(GetNodeAt(List, 0), CreateNode(500));
	PrintList(List);
	printf("count = %d", CountNode(List));
	return (0);
}
