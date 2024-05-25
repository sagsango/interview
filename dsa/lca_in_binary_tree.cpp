// Time O(n)
// space O(1)


int lowestCommonAncester( TreeNode * root, int a, int b, TreeNode * & lca ){
	if( root == NULL )
		return 0;

	int found_nodes = ( root->val == a ) + 
										( root->val == b ) + 
										lowestCommonAncester(root->left, a, b, lca) + 
										lowestCommonAncester(root->right, a, b, lca);

	if( lca == NULL && found_nodes == 2 ){
		lca = root;
	}

	return found_nodes;
}


