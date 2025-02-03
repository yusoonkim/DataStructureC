#include "CDLL.h"

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
