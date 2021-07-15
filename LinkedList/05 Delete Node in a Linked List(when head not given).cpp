/*
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, 
instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 
Since we are given the pointer to the exact node which we have to delete
We know we cannot go back in a singly linked list.
The hack is we will not delete this current node. 
We will copy the content of next node to this current node and delete that next node :p
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete temp;
    }
};
