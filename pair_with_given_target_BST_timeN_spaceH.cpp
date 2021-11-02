// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1/?company[]=Amazon&company[]=Amazon&page=9&query=company[]Amazonpage9company[]Amazon
/*
	 Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum.
 */


class Solution{
	public:
		// root : the root Node of the given BST
		// target : the target sum
		class BSTTraveller{
			public:
				stack<Node*>st;
				BSTTraveller(){};
				virtual ~BSTTraveller(){};
				virtual void add(Node*) = 0;
				virtual void next() = 0;
				int curr(){
					return st.top()->data;
				}
				bool empty(){
					return st.empty();
				}
		};
		class Forward : public BSTTraveller{
			public:
				Forward():BSTTraveller(){}
				~Forward(){}
				void add(Node * root)override{
					while( root ){
						st.push(root);
						root = root->left;
					}
				}
				void next()override{
					Node * root = st.top();
					st.pop();
					add(root->right);
				}
		};
		class Backward: public BSTTraveller{
			public:
				Backward():BSTTraveller(){}
				~Backward(){}
				void add(Node * root)override{
					while( root ){
						st.push(root);
						root = root->right;
					}
				}
				void next()override{
					Node * root = st.top();
					st.pop();
					add(root->left);
				}
		};

		int isPairPresent(struct Node *root, int target)
		{
			//add code here.
			BSTTraveller *F = new Forward();
			BSTTraveller *B = new Backward();
			F->add(root);
			B->add(root);

			while( !F->empty() ){
				while( !B->empty() && B->curr() + F->curr() > target ){
					B->next();
				}
				if( !F->empty() && !B->empty() && F->curr() + B->curr() == target ){
					return 1;
				}
				F->next();
			}
			delete F;
			delete B;
			return 0;

		}
};


