#include "DS.h"

int	main()
{
	DS	*set1 = MakeSet('A');
	DS	*set2 = MakeSet('B');
	DS	*set3 = MakeSet('C');
	DS	*set4 = MakeSet('D');
	printf("set1 == set2 : %d\n", FindSet(set1) == FindSet(set2));
	UnionSet(set1, set2);
	printf("set1 == set2 : %d\n", FindSet(set1) == FindSet(set2));
	printf("set3 == set4 : %d\n", FindSet(set3) == FindSet(set4));
	UnionSet(set3, set4);
	printf("set3 == set4 : %d\n", FindSet(set3) == FindSet(set4));
	UnionSet(set1, set4);
	printf("set1 == set4 : %d\n", FindSet(set1) == FindSet(set4));
	DestroySet(set1);
	DestroySet(set2);
	DestroySet(set3);
	DestroySet(set4);
	return (0);
}
