#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 * Return: A pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *node_uncle = NULL, *node_p = NULL, *node_gp = NULL;

	if (node == NULL)
		return (NULL);

	if (node->parent != NULL)
	{
		node_p = node->parent;

		if (node_p->parent != NULL)
		{
			node_gp = node_p->parent;

			if (node_gp->right->right == node || node_gp->right->left == node)
				node_uncle = node_gp->left;

			if (node_gp->left->left == node || node_gp->left->right == node)
				node_uncle = node_gp->right;
		}
	}

	return (node_uncle);
}
