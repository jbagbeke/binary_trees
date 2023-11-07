#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int r_full = 0, l_full = 0;

	if (tree == NULL)
		return (0);

	l_full = binary_tree_is_full(tree->left);
	r_full = binary_tree_is_full(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (l_full == 1 && r_full == 1)
		return (1);

	return (0);
}
