#ifndef SBT_H
#define SBT_H

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct SimpleBinaryTree
{
	struct SimpleBinaryTree *Left;
	struct SimpleBinaryTree *Right;
	DataType Data;
} SBTNode;

SBTNode	*CreateNode(DataType data);
void	DestroyNode(SBTNode *node);
void	DestroyTree(SBTNode *root);
void	PreorderPrint(SBTNode *root);
void	InorderPrint(SBTNode *root);
void	PostorderPrint(SBTNode *root);

#endif
