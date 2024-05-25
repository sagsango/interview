// Clone a Binary Tree with Random Pointers
// https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/

/*
	 Given a Binary Tree where every node has the following structure.
	 struct node {
			int key;
	 		struct node *left,*right,*random;
	 }
	 The random pointer points to any random node of the binary tree and can even point to NULL, clone the given binary tree.
 */

// case 1: 	Extra space allowed -> use unordered_map
// case 2:  Extra space not allowed, modify tree.

class Solution{
	public:
		/* The function should clone the passed tree and return 
			 root of the cloned tree */

		void modyfy_tree(Node*tree){
			if(tree){
				Node * copy_node = new Node(tree->data);
				copy_node->left = tree->left;
				tree->left = copy_node;

				modyfy_tree(tree->left->left);
				modyfy_tree(tree->right);

			}
		}

		// random points anywhere, so first new random node should be aviable
		// so doing it after copying eveynode.
		void fill_random(Node*tree){
			if(tree){

				if( tree->random )
					tree->left->random = tree->random->left;

				fill_random(tree->left->left);
				fill_random(tree->right);

			}
		}

		Node * recover_tree(Node*tree){
			if(tree){

				Node * copy_node = tree->left;

				tree->left = copy_node->left;

				copy_node->left = recover_tree(tree->left);
				copy_node->right= recover_tree(tree->right);


				return copy_node;
			}
			return NULL;
		}
		Node* cloneTree(Node* tree)
		{
			//Your code here

			modyfy_tree(tree);

			fill_random(tree);

			return recover_tree(tree);
		}
};
