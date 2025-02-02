#include "dll.h"

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
