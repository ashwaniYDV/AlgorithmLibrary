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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        // handles both even and odd length of linkedlist
        ListNode *middle = middleNode(head);
        
        // now reverse the right half of linkedlist and get its head
        ListNode *start2 = reverse(middle);
        
        ListNode *start1 = head;
        
        while(start2) {
            if(start1->val != start2->val) return false;
            start1 = start1->next;
            start2 = start2->next;
        }
        
        return true;   
    }
};
