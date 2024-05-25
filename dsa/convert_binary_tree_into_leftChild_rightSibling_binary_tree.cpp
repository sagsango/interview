// Convert binary tree to Left-child right-sibling binary tree
// https://www.techiedelight.com/convert-normal-binary-tree-left-child-right-sibling-binary-tree/


#include <iostream>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

// Function to perform preorder traversal on a given binary tree.
void preorder(Node* root)
{
	if (root == nullptr) {
		return;
	}

	cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
}

// TODO: Think if some node have only right child.
// Function to convert a normal binary tree into a Left–child
// right–sibling (LC–RS) binary tree
void convert(Node* root)
{
	// base case: empty tree
	if (root == nullptr) {
		return;
	}

	// recursively convert the left and right subtree first
	convert(root->left);
	convert(root->right);

	// if the left child is empty, point it to the right child
	// and set the right child to null
	if (root->left == nullptr)
	{
		root->left = root->right;
		root->right = nullptr;
	}

	// if the left child already exists, then make its right child
	// point to the current node's right child and
	// and set the right child as null
	else {
		root->left->right = root->right;
		root->right = nullptr;
	}
}

int main()
{
	/* Construct the following tree
			  1
			/  \
		   /    \
		  2      3
		 / \    /
		4   5  6
			  / \
			 7   8
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	convert(root);
	preorder(root);

	return 0;
}
