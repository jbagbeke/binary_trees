#include "binary_trees.h"

/**
 * binary_tree_height - Goes via a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * Return: Void
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		node_depth = binary_tree_depth(tree->parent);

	return (node_depth + 1);
}
