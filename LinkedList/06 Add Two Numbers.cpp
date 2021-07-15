// https://leetcode.com/problems/add-two-numbers/

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, total = 0;
        ListNode *curr = new ListNode(); 
        ListNode *res = curr, *prev = NULL;
        while(l1 && l2) {
            total = l1->val + l2->val + carry;
            curr->val = total % 10;
            carry = total / 10;
            prev = curr;
            curr->next = new ListNode();
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            total = l1->val + carry;
            curr->val = total % 10;
            carry = total / 10;
            prev = curr;
            curr->next = new ListNode();
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            total = l2->val + carry;
            curr->val = total % 10;
            carry = total / 10;
            prev = curr;
            curr->next = new ListNode();
            curr = curr->next;
            l2 = l2->next;
        }
        while(carry) {
            curr->val = carry % 10;
            carry /= 10;
            prev = curr;
            curr->next = new ListNode();
            curr = curr->next;
        }
        prev->next = NULL;

        return res;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, total = 0;
        ListNode *curr = new ListNode(); 
        ListNode *res = curr;
        while(l1 && l2) {
            total = l1->val + l2->val + carry;
            curr->next = new ListNode(total % 10);
            carry = total / 10;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            total = l1->val + carry;
            curr->next = new ListNode(total % 10);
            carry = total / 10;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            total = l2->val + carry;
            curr->next = new ListNode(total % 10);
            carry = total / 10;
            curr = curr->next;
            l2 = l2->next;
        }
        while(carry) {
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            curr = curr->next;
        }

        return res->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr = new ListNode();
        ListNode *res = curr;
        int carry = 0, total = 0;
        while(l1 || l2 || carry) {
            total = 0;
            if(l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                total += l2->val;
                l2 = l2->next;
            }
            
            total += carry;
            curr->next = new ListNode(total % 10);;
            curr = curr->next;
            carry = total / 10;
        }
        
        return res->next;
    }
};
