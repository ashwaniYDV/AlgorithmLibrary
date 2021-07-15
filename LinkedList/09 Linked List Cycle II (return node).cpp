// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        
        ListNode* slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            // for getting the intersection point
            if(slow == fast) {
                ListNode* slow2 = head;
                while(slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            };
        }
        
        return NULL;
    }
};
