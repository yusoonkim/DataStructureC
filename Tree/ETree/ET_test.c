#include "ET.h"

int	main()
{
	ETNode	*root;
	char	str[20] = "212*+324*+/";
	BuildTree(&root, str);
	printf("%f", EvaluateTree(root));
	return (0);
}