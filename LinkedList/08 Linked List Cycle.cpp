// https://youtu.be/wiOo4DC5GGA?si=vt8znZokzn638CIn
// https://youtu.be/QfbOhn0WZ88?si=6kPSGKbn1xFCEka6
// https://youtu.be/2Kd0KKmmHFc?si=8-Fx-ffv_MO9SFdd

// https://leetcode.com/problems/linked-list-cycle/
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






// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// Find the length of a loop in linked list.

int countNodesinLoop(struct Node *head) {
    if(!head || !head->next) return 0;
    
    Node* slow = head, *fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // for getting the intersection point
        if(slow == fast) {
            Node* temp = slow->next;
            int cnt = 1;
            while(temp != slow) {
                temp = temp->next;
                cnt++;
            }
            return cnt;
        };
    }
    
    return 0;
}
