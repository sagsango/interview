// Min distance between two given nodes of a Binary Tree 
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
/*
	 Given a binary tree and two node values your task is to find the minimum distance between them.
 */

/*
	 struct Node
	 {
	 		int data;
	 		Node* left, * right;
	 }; 
 */

class Solution{
	public:
		/* Should return minimum distance between a and b
			 in a tree with given root*/
		int dfs(Node * root,int &a,int &b,int h,int &hl, int &ha, int &hb){
			int cur_cnt = 0;
			if( root ){
				if( root->data == a ){
					cur_cnt += 1;
					ha = h;
				}
				if( root->data == b ){
					cur_cnt += 1;
					hb = h;
				}
				cur_cnt += dfs(root->left, a,b,h+1,hl,ha,hb);
				cur_cnt += dfs(root->right,a,b,h+1,hl,ha,hb);
				if( cur_cnt == 2 && hl == -1){ //TODO: When to update, when not to update
					hl = h;
				}
			}
			return cur_cnt;
		}
		int findDist(Node* root, int a, int b) {
			// Your code here
			int hl = -1, ha = -1, hb = -1;
			dfs(root,a,b,0,hl,ha,hb);
			return ha + hb - 2*hl;
		}
};

