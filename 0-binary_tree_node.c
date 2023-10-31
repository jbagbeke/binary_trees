#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node of the binary tree
 * @parent: The root of the binary tree
 * @value: Value to be assigned to each node
 * Return: Pointer to the Binary Tree created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *p_node, *ptr;

	p_node = malloc(sizeof(binary_tree_t));

	if (!p_node)
		return NULL;

	p_node->n = value;
	p_node->left = NULL;
	p_node->right = NULL;

	parent = p_node->parent;
	ptr = p_node;

	return (ptr);
}
