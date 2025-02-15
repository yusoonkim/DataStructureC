#include "DS.h"

DS	*FindSet(DS *set)
{
	while (set->Parent != NULL)
		set = set->Parent;
	return (set);
}

void	UnionSet(DS *set1, DS *set2)
{
	set2 = FindSet(set2);
	set2->Parent = set1;
}

DS	*MakeSet(DataType data)
{
	DS	*new = (DS*)malloc(sizeof(DS));
	new->Parent = NULL;
	new->Data = data;
	return (new);
}
void	DestroySet(DS *set)
{
	free(set);
}