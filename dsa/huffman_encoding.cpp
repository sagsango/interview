// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1/?company[]=Amazon&company[]=Amazon&page=22&query=company[]Amazonpage22company[]Amazon

/*
	 Given a string S of distinct character of size N and their corresponding frequency 
	 f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree 
	 print all the huffman codes in preorder traversal of the tree.
 */


// TODO: Use priority queue of node
class Solution{
	private:
		struct Node{
			int val;
			int idx; // idx = -1, for non leaf.
			Node *l, *r;
			Node(int val,int idx = -1){
				this->val = val;
				this->idx = idx;
				l = r = NULL;
			}
		};

		struct box{
			Node * node;
			bool operator<(const box & other)const{
				return this->node->val > other.node->val;
			}
		};

		vector<string>ans;
		string s;


		void dfs(Node * root ){
			if( root == NULL )
				return;
			if( root->idx != -1 ){
				ans.push_back(s);
			}else{
				s += '0';
				dfs(root->l);
				s.pop_back();

				s += '1';
				dfs(root->r);
				s.pop_back();

				delete root; // TODO: Always free the memory what you have allocated on heap.
			}
		}
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
			// Code here
			priority_queue<box>pq;
			for(int i=0;i<N;++i){
				pq.push({new Node(f[i],i)});
			}

			while( pq.size() != 1 ){
				box l = pq.top(); pq.pop();
				box r = pq.top(); pq.pop();

				Node *root = new Node({l.node->val+r.node->val});
				root->l = l.node;
				root->r = r.node;
				pq.push({root});
			}

			ans.clear();
			s.clear();


			dfs( pq.top().node );

			return ans;

		}
};
