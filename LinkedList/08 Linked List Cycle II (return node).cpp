// https://leetcode.com/problems/linked-list-cycle-ii/
// https://youtu.be/wiOo4DC5GGA?si=vt8znZokzn638CIn

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            // for getting the intersection point
            if(slow == fast) {
                ListNode* slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            };
        }
        
        return NULL;
    }
};
