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

ETNode	*CreateNode(DataType data)
{
	ETNode	*node = (ETNode*)malloc(sizeof(ETNode));
	node->Left = NULL;
	node->Right = NULL;
	node->Data = data;
	return (node);
}

void	DestroyNode(ETNode *node)
{
	free(node);
}

void	DestroyTree(ETNode *root)
{
	if (root == NULL)
		return ;
	DestroyTree(root->Left);
	DestroyTree(root->Right);
	DestroyNode(root);
}

void	PreorderPrint(ETNode *root)
{
	if (root == NULL)
		return ;
	printf(" %c", root->Data);
	PreorderPrint(root->Left);
	PreorderPrint(root->Right);
}

void	InorderPrint(ETNode *root)
{
	if (root == NULL)
		return ;
	InorderPrint(root->Left);
	printf(" %c", root->Data);
	InorderPrint(root->Right);
}

void	PostorderPrint(ETNode *root)
{
	if (root == NULL)
		return ;
	PostorderPrint(root->Left);
	PostorderPrint(root->Right);
	printf(" %c", root->Data);
}

void	BuildTree(ETNode **root, char *str)
{
	int	len = strlen(str) - 1;
	char	token;
	token = str[len];
	str[len] = '\0';
	if (token == '-' || token == '+' || token == '*' || token == '/')
	{
		*root = CreateNode(token);
		BuildTree(&(*root)->Right, str);
		BuildTree(&(*root)->Left, str);
	}
	else
		*root = CreateNode(token);
}

double	EvaluateTree(ETNode *root)
{
	if (root == NULL)
		return (0);
	char	token = root->Data;
	if (token == '-' || token == '+' || token == '*' || token == '/')
	{
		if (token == '-')
			return (EvaluateTree(root->Left) - EvaluateTree(root->Right));
		else if (token == '+')
			return (EvaluateTree(root->Left) + EvaluateTree(root->Right));
		else if (token == '*')
			return (EvaluateTree(root->Left) * EvaluateTree(root->Right));
		else
			return (EvaluateTree(root->Left) / EvaluateTree(root->Right));
	}
	else
	{
		char	data[2] = {};
		data[0] = token;
		return (atof(data));
	}
}

int	main()
{
	ETNode	*root;
	char	str[20] = "212*+324*+/";
	BuildTree(&root, str);
	printf("%f", EvaluateTree(root));
	return (0);
}
