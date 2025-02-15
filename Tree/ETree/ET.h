#ifndef ET_H
#define ET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;

typedef struct ExpressionTree
{
	struct ExpressionTree	*Left;
	struct ExpressionTree	*Right;
	DataType	Data;
} ETNode;

ETNode	*CreateNode(DataType data);
void	DestroyNode(ETNode *node);
void	DestroyTree(ETNode *root);
void	PreorderPrint(ETNode *root);
void	InorderPrint(ETNode *root);
void	PostorderPrint(ETNode *root);
void	BuildTree(ETNode **root, char *str);
double	EvaluateTree(ETNode *root);

#endif
