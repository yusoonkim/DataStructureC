#include "LCRS.h"

int	main()
{
	Node	*root = CreateNode('A');
	Node	*B = CreateNode('B');
	Node	*C = CreateNode('C');
	Node	*D = CreateNode('D');
	Node	*E = CreateNode('E');
	Node	*F = CreateNode('F');
	Node	*G = CreateNode('G');
	AddChildNode(root, B);
	AddChildNode(root, E);
	AddChildNode(root, G);
	AddChildNode(B, C);
	AddChildNode(C, D);
	AddChildNode(E, F);
	PrintTree(root, 0);
	printf("CountNodes : %d\n", CountNodes(root));
	printf("CountLeafs : %d\n", CountLeafs(root));
	DestroyTree(root);
}