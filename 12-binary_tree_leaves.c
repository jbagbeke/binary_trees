#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to root node of tree to count the number of leaves
 * Return: 1 if a leaf and 0 otherwise
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaf = 0, right_leaf = 0, total_leaf = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_leaf = binary_tree_leaves(tree->left);
	right_leaf = binary_tree_leaves(tree->right);

	total_leaf = right_leaf + left_leaf;

	return (total_leaf);
}
