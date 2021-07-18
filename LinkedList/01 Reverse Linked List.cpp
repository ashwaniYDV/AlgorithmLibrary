// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode *prev = NULL, *cur = head, *nxt = NULL;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};






// recursive

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        // search for new head via recursion
        ListNode* new_head = reverseList(head->next);

        // reverse list: make next node point to this node
        head->next->next = head;

        // tricky part: make cur node point to null. Only stays null for new tail
        // otherwise, the line above sets this node to point to the previous node
        // on the next recursion
        head->next = NULL;

        // continue to pass new head along to original function call
        return new_head;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* new_head = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;
        
        return new_head;
    }
};
