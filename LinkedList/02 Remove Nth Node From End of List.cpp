// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


// Optimized O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head; 
        if(head->next == NULL && n == 1) return NULL;
        
        ListNode *slow = head, *fast = head;
        
        for(int i = 0; i < n; i++) fast = fast->next;
        
        if(fast == NULL)  {
            return head->next;
        }
        
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};



// Naive O(2n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        if(head->next == NULL && n == 1) return NULL;
        
        ListNode* temp=head;
        
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        
        int num = count - n;
        if(num == 0) {
            head = head->next; 
            return head;
        }
        
        temp = head;
        num--;
        while(num--){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        
        return head;
    }
};
