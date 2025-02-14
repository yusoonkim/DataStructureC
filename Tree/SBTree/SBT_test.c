#include "SBT.h"

int	main()
{
	SBTNode	*A = CreateNode('A');
	SBTNode	*B = CreateNode('B');
	SBTNode	*C = CreateNode('C');
	SBTNode	*D = CreateNode('D');
	SBTNode	*E = CreateNode('E');
	SBTNode	*F = CreateNode('F');
	SBTNode	*G = CreateNode('G');
	A->Left = B;
	B->Left = D;
	A->Right = C;
	C->Left = E;
	C->Right = F;
	F->Right = G;
	printf("Preorder :");
	PreorderPrint(A);
	printf("\n\nInorder : ");
	InorderPrint(A);
	printf("\n\nPostorder : ");
	PostorderPrint(A);
	printf("\n\n");
	DestroyTree(A);
	return (0);
}