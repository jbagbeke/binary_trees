#include "binary_trees.h"

/**
 * node_depth - Determines depth of a node
 * @node: Pointer to node to determine
 * Return: Depth of the node
 */
int node_depth(binary_tree_t *node)
{
	int depth;

	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (0);

	depth = node_depth(node->parent);

	return (depth + 1);
}


/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @fst: Pointer to the first node
 * @scd: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(binary_tree_t *fst, binary_tree_t *scd)
{
	binary_tree_t *node_point = NULL, *node1 = fst, *node2 = scd, *alt = NULL;
	int first_depth, second_depth;

	if (fst == NULL || scd == NULL)
		return (NULL);
	if (fst == scd)
		return (fst);

	first_depth = node_depth(fst);
	second_depth = node_depth(scd);

	if (first_depth > second_depth)
	{
		node_point = fst;
		alt = scd;
	}
	else if (second_depth > first_depth)
	{
		node_point = scd;
		alt = fst;
	}

	if (node_point != NULL)
	{
		while (node_point->parent != NULL && node_point->parent != alt->parent)
		{
			if (node_point->parent == alt)
				return (alt);
			node_point = node_point->parent;
		}
		if (node_point != NULL)
			return (node_point->parent);
	}

	while (node1->parent != NULL && node1->parent != node2->parent)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return (node1->parent);
}
