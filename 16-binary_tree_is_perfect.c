#include "binary_trees.h"

/**
 * full_tree - Checks if a binary tree is full
 * @tree: Pointer to the root of the tree
 * Return: 1 if full, 0 otherwise
 */
int full_tree(const binary_tree_t *tree)
{
	int left_full = 0, right_full = 0;

	if (tree == NULL)
		return (0);

	left_full = full_tree(tree->left);
	right_full = full_tree(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((left_full == 1) && (right_full == 1))
		return (1);

	return (0);
}


/**
 * tree_height - Checks the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}


/**
 * binary_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: 1 is atleast a node present, 0 otherwise
 */
int binary_nodes(const binary_tree_t *tree)
{
	int left_node = 0, right_node = 0;

	if (tree == NULL)
		return (0);

	left_node = binary_nodes(tree->left);
	right_node = binary_nodes(tree->right);


	return (left_node + right_node + 1);
}


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Phecks if a binary tree is perfect
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int full_binary = 0, binary_height = 0;
	int height = 0, node_count = 0;

	full_binary = full_tree(tree);

	if (full_binary == 0)
		return (0);

	binary_height = tree_height(tree);

	node_count = binary_nodes(tree);

	height = (1 << (binary_height + 1)) - 1;

	if (height != node_count)
		return (0);

	return (1);
}
