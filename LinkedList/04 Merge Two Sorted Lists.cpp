// https://leetcode.com/problems/merge-two-sorted-lists/

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
 
 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val > l2->val) std::swap(l1, l2);
        
        ListNode *res = l1;
        
        while(l1 && l2) {
            ListNode *temp = NULL;
            while(l1 && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        
        return res;
    }
};
 




// naive solution (not memory efficient)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *curr = new ListNode();
        ListNode *res = curr;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
                
            } else {
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while(l1) {
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }
        return res->next;
    }
};
