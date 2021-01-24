// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
        
        temp = head;
        int num = count - n - 1;
        if(num == -1) {
            head = head->next; 
            return head;
        }
        
        while(num--){
            temp = temp->next;
        }
        if(temp->next != NULL) temp->next = temp->next->next;
        
        return head;
    }
};



// Optimized O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head; 
        if(head->next == NULL && n == 1) return NULL;
        
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *slow = start, *fast = start;
        
        for(int i = 1; i <= n; i++) fast = fast->next;
        
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};
