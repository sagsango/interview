// Convert a Binary Tree to Threaded binary 
// https://www.techiedelight.com/threaded-binary-tree-overview-implementation/
// https://www.geeksforgeeks.org/convert-binary-tree-threaded-binary-tree-set-2-efficient/

/*
	 Idea of Threaded Binary Tree is to make inorder traversal faster and do it without stack and without recursion.
	 In a simple threaded binary tree, the NULL right pointers are used to store inorder successor. 
	 Where-ever a right pointer is NULL, it is used to store inorder successor.
 */




struct Node{
	int val;
	Node * left, * right;
	bool isThreaded; // right pointer is a threaded pointer or normal right pointer
	Node(int val):val(val),left(NULL),right(NULL){}
};


class BTreeTravler{
	private:
		stack<Node*>m_stack;
	public:
		BTreeTravler(Node*);
		~BTreeTravler();
		void Next();
		void Add(Node*);
		Node*Curr();
		bool Empty();
};

BTreeTravler::BTreeTravler(Node*root){
	Add(root);
}

~BTreeTravler::BTreeTravler(){
}

void BTreeTravler::Add(Node*root){
	while( root ){
		m_stack.push(root);
		root=root->left;
	}
}

void BTreeTravler::Next(){
	Node * root = m_stack.top();
	m_stack.pop();
	Add(root->right);
}

Node*Curr(){
	return m_stack.top();
}

bool Empty(){
	return m_stack.empty();
}



// convert BST into threaded binary tree
void convertBTreeToThreadedTree(Node * root){
	BTreeTravler traveler(root);
	Node * prv_node = NULL;
	while( ! traveler.empty() ){
		cur_node = traveler.Curr();
		if( prv_node && prv_node->right == NULL ){
			prv_node->right = cur_node;
			prv_node->isThreaded = True;
		}
		traveler.Next();
	}
}


// inorder traversal in threaded binary three without any extra space
void inOderderTraveralOfThreadedTree(){
	while( root && root->left )
		root = root->left;
	while( root ){
		cout << root->val << endl;
		if( root->isThreaded )
			root = root->right;
		else{
			root = root->right;
			while( root && root->left )
				root = root->left;
		}
	}
}









