// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/

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


// slow fast pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode *slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        
        return false;
    }
};
