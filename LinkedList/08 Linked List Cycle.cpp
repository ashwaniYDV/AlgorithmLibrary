// https://leetcode.com/problems/linked-list-cycle/
// https://youtu.be/wiOo4DC5GGA?si=vt8znZokzn638CIn

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        
        return false;
    }
};


// https://leetcode.com/problems/linked-list-cycle-ii/
// https://youtu.be/wiOo4DC5GGA?si=vt8znZokzn638CIn

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
