/*
https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/

272. Closest Binary Search Tree Value II
Solved
Hard


Given the root of a binary search tree, a target value, and an integer k, return the k values in the BST that are closest to the target. You may return the answer in any order.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

 

Example 1:
Input: root = [4,2,5,1,3], target = 3.714286, k = 2
Output: [4,3]

Example 2:
Input: root = [1], target = 0.000000, k = 1
Output: [1]
 

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104.
0 <= Node.val <= 109
-109 <= target <= 109
 
Follow up: Assume that the BST is balanced. Could you solve it in less than O(n) runtime (where n = total nodes)?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


 class treeTravelerForward {
    stack <TreeNode*> st;
    public:
    void insert (TreeNode * root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    public:
    treeTravelerForward(TreeNode * root) {
        insert(root);
    }
    void next() {
        TreeNode * root = st.top();
        st.pop();
        insert(root->right);
    }

    TreeNode * current() {
        return st.top();
    }

    int size() {
        return st.size();
    }

    bool empty() {
        return st.empty();
    }
 };

 class treeTravelerBackword {
    stack <TreeNode*> st;
 
    void insert (TreeNode * root) {
        while (root) {
            st.push(root);
            root = root->right;
        }
    }
    public:
    treeTravelerBackword(TreeNode * root) {
        insert(root);
    }
    void next() {
        TreeNode * root = st.top();
        st.pop();
        insert(root->left);
    }

    TreeNode * current() {
        return st.top();
    }

    int size() {
        return st.size();
    }

    bool empty() {
        return st.empty();
    }
 };


int countNodes(TreeNode * root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {

        /*
            So lets say there is a sorted array;
            and we want to find the closest k values

            we can use the shrinking window approach
            l = 0, r = n-1
            while ( r - l + 1 > k ){
                int diff_l = abs(nums[l] - k);
                int diff_r = abs(nums[r] - k);

                if (diff_l > diff_r) {
                    l += 1;
                } else {
                    r -= 1;
                }
            }
            // now l to r is the window
        */

        treeTravelerForward l(root);
        treeTravelerBackword r(root);

        int rem = 0, n = countNodes(root);

        while (n - rem > k) {
            double l_diff = abs(target - l.current()->val);
            double r_diff = abs(target - r.current()->val);

            if (l_diff > r_diff) {
                l.next();
            } else {
                r.next();
            }

            rem += 1;
        }

        // it have k elements

        vector<int> ans;

        for (;;){
            ans.push_back(l.current()->val);
            if (l.current() == r.current()) {
                break;
            }
            l.next();
        }

        return ans;
    }
};
