#ifndef DS_H
#define DS_H

#include <stdio.h>
#include <stdlib.h>

typedef char	DataType;

typedef struct DisjointSet
{
	struct DisjointSet	*Parent;
	DataType	Data;
} DS;

DS	*FindSet(DS *set);
void	UnionSet(DS *set1, DS *set2);
DS	*MakeSet(DataType data);
void	DestroySet(DS *set);

#endif
