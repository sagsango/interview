// https://leetcode.com/problems/copy-list-with-random-pointer/



/*
	 A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
	 Construct a deep copy of the list.
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node * cur = NULL,*copy_node;

        // fill copy node, inside the list
        cur = head;
        while( cur ){
            copy_node = new Node( cur->val );
            copy_node->next = cur->next;
            cur->next = copy_node;
            cur = cur->next->next;
        }

        // copy randome pointer
        cur = head;
        while( cur ){
            if( cur->random )
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // recover the origional list
        Node * copy_head = NULL, * copy_tail = NULL;
        cur = head;
        while( cur ){
            copy_node = cur->next;
            cur->next = cur->next->next;
            if( copy_tail ){
                copy_tail->next = copy_node;
                copy_tail = copy_node;
            }else{
                copy_head = copy_tail = copy_node;
            }
            copy_tail->next = NULL;
            cur = cur->next;
        }
        return copy_head;

    }
};
