#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: Pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling_node = NULL;

	if (node == NULL)
		return (NULL);

	if (node->parent != NULL)
	{
		if (node->parent->left == node && node->parent->right != NULL)
			sibling_node = node->parent->right;

		if (node->parent->right == node && node->parent->left != NULL)
			sibling_node = node->parent->left;
	}

	return (sibling_node);
}
