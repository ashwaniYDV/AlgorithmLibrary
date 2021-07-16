// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
 
 // recursive soln
class Solution {
public:    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0; 
        ListNode *temp = head;
        while(temp && count < k) {
            temp = temp->next;
            count++;
        }
        
        // if we dont have enought nodes
        if(count < k) return head;
        
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        count = 0;
        // reversing the first K nodes
        while(curr and count < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        
        // if the next segment nodes is not null
        if(curr) head->next = reverseKGroup(curr, k);
        
        return prev;
    }
};
