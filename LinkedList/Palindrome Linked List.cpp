// https://leetcode.com/problems/palindrome-linked-list/

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
 
// since list is modified in this method
// but if you want original list back, we can again reverse the reversed part to nullify the reverse effect
class Solution {
public:
    ListNode* reverse(ListNode *curr) {
        ListNode *prev = NULL, *nxt = NULL;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode *slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // handles both even and odd length of linkedlist
        slow = slow->next;
        
        // now reverse the right half of linkedlist and get its head
        ListNode *temp2 = reverse(slow);
        
        ListNode *temp1 = head;
        
        while(temp2) {
            if(temp1->val != temp2->val) return false;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return true;   
    }
};
