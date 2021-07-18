// https://leetcode.com/problems/partition-list/

/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Input: head = [2,1], x = 2
Output: [1,2]
*/


// Space = O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head;
        ListNode *first = new ListNode, *second = new ListNode;
        ListNode *tempfirst = first, *tempsecond = second;
        
        while(temp) {
            if(temp->val < x) {
                tempfirst->next = new ListNode(temp->val);
                tempfirst = tempfirst->next;
            } else {
                tempsecond->next = new ListNode(temp->val);
                tempsecond = tempsecond->next;
            }
            temp = temp->next;
        }
        
        tempfirst->next = second->next;
        return first->next;
    }
};
