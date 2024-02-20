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






// https://www.geeksforgeeks.org/problems/find-length-of-loop/1

Node* getCycleNode(Node *head) {
    if(!head || !head->next) return NULL;
    
    Node* slow = head, *fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        // for getting the intersection point
        if(slow == fast) {
            Node* slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        };
    }
    
    return NULL;
}

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    if (!head) return 0;
    Node* cycleNode = getCycleNode(head);
    if (!cycleNode) return 0;
    
    Node* temp = cycleNode;
    int res = 1;
    while(temp->next != cycleNode) {
        res++;
        temp = temp->next;
    }
    return res;
}
