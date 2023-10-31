#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node or NULL in case of failure
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *b_node, *ptr;

	if (parent == NULL)
		return (NULL);

	b_node = malloc(sizeof(binary_tree_t));

	if (!b_node)
		return (NULL);

	b_node->n = value;
	b_node->right = NULL;
	b_node->left = NULL;

	if (parent->left != NULL)
	{
		ptr = parent->left;
		parent->left = b_node;
		b_node->parent = parent;
		b_node->left = ptr;
		ptr->parent = b_node;
	}
	else
	{
		parent->left = b_node;
		b_node->parent = parent;
	}

	ptr = b_node;

	return (ptr);
}
