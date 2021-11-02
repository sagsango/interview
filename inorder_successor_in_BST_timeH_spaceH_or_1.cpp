// https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/


// case 1: have parent pointer
// case 2: do not have parent pointer


// C++ Program to find inorder successor.
#include<bits/stdc++.h>
using namespace std;

// structure of a Binary Node.
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Function to create a new Node.
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// function that prints the inorder successor
// of a target node. next will point the last
// tracked node, which will be the answer.
void inorderSuccessor(Node* root,
		Node* target_node,
		Node* &next)
{
	// if root is null then return
	if(!root)
		return;

	inorderSuccessor(root->right, target_node, next);

	// if target node found then enter this condition
	if(root->data == target_node->data)
	{
		// this will be true to the last node
		// in inorder traversal i.e., rightmost node.
		if(next == NULL)
			cout << "inorder successor of "
				<< root->data << " is: null\n";
		else
			cout << "inorder successor of "
				<< root->data << " is: "
				<< next->data << "\n";
	}
	next = root;
	inorderSuccessor(root->left, target_node, next);
}

// Driver Code
int main()
{

	// Let's construct the binary tree
	//		 1
	// / \
	// 2	 3
	// / \ / \
	// 4 5 6 7
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	// Case 1
	Node* next = NULL;
	inorderSuccessor(root, root, next);

	// case 2
	next = NULL;
	inorderSuccessor(root, root->left->left, next);

	// case 3
	next = NULL;
	inorderSuccessor(root, root->right->right, next);

	return 0;
}

// This code is contributed by AASTHA VARMA


