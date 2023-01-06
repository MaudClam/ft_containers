void			transplant(node_pointer node, node_pointer rm_node) {
	bool			color = node->color;
	node_pointer	parent = node->parent;
	node_pointer	left = node->left;//rm_node
	node_pointer	right = node->right;//rm_rm
	
	node->color = rm_node->color;
	rm_node->color = color;
	
	if (node->parent == NULL)
		root = rm_node;
	else if (node == node->parent->left)
		node->parent->left = rm_node;
	else
		node->parent->right = rm_node;

	if (rm_node == rm_node->parent->left)
		rm_node->parent->left = node;
	else
		rm_node->parent->right = node;
	
	
	if (node->left != NULL)
		node->left->parent = rm_node;
	if (node->right != NULL)
		node->right->parent = rm_node;
	
	if (rm_node->left != NULL)
		rm_node->left->parent = node;
	if (rm_node->right != NULL)
		rm_node->right->parent = node;

if (node == rm_node->parent) {
	node->parent = rm_node;
	rm_node->parent = parent;
	
	node->left = rm_node->left;
	node->right = rm_node->right;

	if (rm_node == left) {
		rm_node->left = node;
		rm_node->right = right;
	}
	else {
		rm_node->right = node;
		rm_node->left = left;
	}
}
else {
	node->parent = rm_node->parent;
	rm_node->parent = parent;
	
	node->left = rm_node->left;
	rm_node->left = left;
	
	node->right = rm_node->right;
	rm_node->right = right;
	}
}
