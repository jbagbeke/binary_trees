#include "binary_trees.h"

/**
 * binary_tree_height - Goes via a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * Return: Void
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height++;

	if (tree->right != NULL)
		height++;

	binary_tree_height(tree->left);
	binary_tree_height(tree->right);

	return (height);
}
