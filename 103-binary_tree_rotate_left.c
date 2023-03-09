#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent, *tparent;

	parent = tree;
	tparent = parent->left;

	parent->left = tparent->right;
	tparent->right = parent;

	return (tparent);
}