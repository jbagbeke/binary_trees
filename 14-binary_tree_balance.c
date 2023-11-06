#include "binary_trees.h"

/**
 * tree_height - Determines height of a node
 * @tree: Pointer to the nde to determine the value of
 * Return: The height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int rt_height = 0, lt_height = 0;

	if (tree == NULL)
		return (0);

	lt_height = tree_height(tree->left);
	rt_height = tree_height(tree->right);

	if (tree->parent == NULL)
		return (lt_height > rt_height ? lt_height : rt_height);
	else
		return (lt_height > rt_height ? lt_height + 1 : rt_height + 1);
}


/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_nodes = 0, left_nodes = 0;

	if (tree == NULL)
		return (0);

	left_nodes = tree_height(tree->left);
	right_nodes = tree_height(tree->right);

	return (left_nodes - right_nodes);
}
