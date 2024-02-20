// https://leetcode.com/problems/linked-list-cycle/
// https://youtu.be/wiOo4DC5GGA?si=vt8znZokzn638CIn

// slow fast pointer
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

// not memory efficient
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        map<ListNode*, int> mp;
        
        while(head) {
            if(mp[head]) return true;
            mp[head] = 1;
            head = head->next;
        }
        
        return false;
    }
};
