#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t right_size = 0, left_size = 0, tree_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_size += binary_tree_size(tree->left);
	right_size += binary_tree_size(tree->right);

	tree_size = left_size + right_size;

	return (tree_size + 1);
}
