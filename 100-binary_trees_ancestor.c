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
	binary_tree_t *first_point = NULL, *second_point = NULL;
	int first_depth, second_depth;

	if (fst == NULL || scd == NULL)
		return (NULL);

	first_depth = node_depth(fst);
	second_depth = node_depth(scd);

	if (first_depth > second_depth)
	{
		first_point = fst;

		while (first_point->parent != NULL && first_point->parent != scd->parent)
		{
			if (first_point->parent == scd)
				return (scd);

			first_point = first_point->parent;
		}

		if (first_point != NULL)
			return (first_point->parent);
	}
	else if (second_depth > first_depth)
	{
		second_point = scd;

		while (second_point->parent != NULL && second_point->parent != fst->parent)
		{
			if (second_point->parent == fst)
				return (fst);

			second_point = second_point->parent;
		}

		if (second_point != NULL)
			return (second_point->parent);
	}

	return (fst->parent);
}
