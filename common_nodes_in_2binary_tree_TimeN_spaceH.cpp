// https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/?company[]=Amazon&company[]=Amazon&page=6&query=company[]Amazonpage6company[]Amazon
/*
	 Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.
*/

class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    struct MyTree{
        stack<Node*>st;
        void add(Node *root){
            while( root ){
                st.push(root);
                root = root->left;
            }
        }
        int top(){
            return st.top()->data;
        }
        void pop(){
            Node * root = st.top();
            st.pop();
            add(root->right);
        }
        bool empty(){
            return st.empty();
        }
    };

    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
         MyTree T1, T2;
         T1.add( root1 );
         T2.add( root2 );

         vector<int>common_nodes;

         while( !T1.empty() && !T2.empty() ){
             if( T1.top() == T2.top() ){
                 common_nodes.push_back( T1.top() );
                 T1.pop();
                 T2.pop();
             }else if( T1.top() < T2.top() ){
                 T1.pop();
             }else if( T2.top() < T1.top() ){
                 T2.pop();
             }
         }

         return common_nodes;
    }
};
