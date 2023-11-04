#include "binary_trees.h"

/**
 * binary_tree_height - Goes via a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * Return: Void
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	return (l_height > r_height ? l_height + 1 : r_height + 1);
}
