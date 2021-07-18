// https://leetcode.com/problems/add-two-numbers/

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/



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




// Using existing l1 for storing answer
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        int carry = 0, total = 0; 
        ListNode *res = l1, *prev;
        
        while(l1 && l2) {
            total = l1->val + l2->val + carry;
            l1->val = total % 10;
            carry = total / 10;
            
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            total = l1->val + carry;
            l1->val = total % 10;
            carry = total / 10;
            
            prev = l1;
            l1 = l1->next;
        }
        while(l2) {
            total = l2->val + carry;
            prev->next = new ListNode(total % 10);
            carry = total / 10;
            
            prev = prev->next;
            l2 = l2->next;
        }
        while(carry) {
            prev->next = new ListNode(carry % 10);
            carry /= 10;
            
            prev = prev->next;
        }

        return res;
    }
};
