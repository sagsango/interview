// https://www.interviewbit.com/problems/reorder-list/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TODO: ass how to pass referance pointer
void  reverseList(ListNode* &given_head){
    ListNode *previous_node, *current_node, *next_node;

    previous_node = NULL;
    current_node = given_head;

    while( current_node ){

        next_node = current_node->next;

        current_node->next = previous_node;

        previous_node = current_node;

        current_node = next_node;
    }

    given_head = previous_node;


}

void cutListIntoTwoHalfs(ListNode* &left_head, ListNode* &right_head, ListNode * given_head){
    left_head = given_head;

    ListNode *slow_pointer, *fast_pointer;

    if( given_head == NULL || given_head->next == NULL ){
        left_head = given_head;
        right_head = NULL;
        return;
    }

    slow_pointer = given_head;
    fast_pointer = given_head->next;

    while( fast_pointer != NULL && fast_pointer->next != NULL ){

        slow_pointer = slow_pointer->next;

        fast_pointer = fast_pointer->next->next;

    }

    right_head = slow_pointer->next;
    slow_pointer->next = NULL;



}

void insertNodeAtHead( ListNode* &given_head, ListNode * new_node){
    new_node->next = given_head;
    given_head = new_node;
}

ListNode* Solution::reorderList(ListNode* given_head) {

    ListNode *left_head, *right_head, *next_node;
    ListNode *new_head;

    cutListIntoTwoHalfs( left_head, right_head, given_head);


    reverseList( right_head );

    bool parity = false;

    given_head = NULL;

    int cnt = 0;

    while( left_head != NULL || right_head != NULL ){
        if( parity == false ){
            next_node = left_head->next;
            insertNodeAtHead(given_head, left_head);
            left_head = next_node; 

        }else{
            next_node = right_head->next;
            insertNodeAtHead(given_head, right_head);
            right_head = next_node;

        }
        parity ^= true; 
    }
    reverseList(given_head);
    return given_head;


}

