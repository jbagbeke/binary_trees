#include "binary_trees.h"

/**
 * binary_tree_depth - Clacs the depth of a node in a binary tree
 * @tree: Node in the tree to calc depth of
 * Return: depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	node_depth = binary_tree_depth(tree->parent);

	return (node_depth + 1);
}
