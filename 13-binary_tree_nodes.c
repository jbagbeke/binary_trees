#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: 1 is atleast a node present, 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_node = 0, right_node = 0, one_node = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		one_node += 1;

	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);

	return (left_node + right_node + one_node);
}
