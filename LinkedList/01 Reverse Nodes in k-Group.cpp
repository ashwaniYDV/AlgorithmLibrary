// https://leetcode.com/problems/reverse-nodes-in-k-group/

 
// recursive soln
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // step 1: check if k elements are thre or not
        int cnt = 0;
        ListNode* temp = head;
        while(cnt < k && temp) {
            temp = temp->next;
            cnt++;
        }
        
        if(cnt < k) return head;

        // step 2: reverse the LL of size k
        ListNode* prev = NULL, *cur = head, *next = NULL;
        cnt = 0;
        while(cnt < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }

        // step 3: recursive call
        head->next = reverseKGroup(temp, k);
        return prev;
    }
};




class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = NULL, *cur = head, *next = NULL;
        int cnt = 0;
        while(cnt < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // step 1: check if k elements are thre or not
        int cnt = 0;
        ListNode* temp = head;
        while(cnt < k && temp) {
            temp = temp->next;
            cnt++;
        }
        
        if(cnt < k) return head;

        // step 2: reverse the LL of size k
        ListNode* prev = reverse(head, k);

        // step 3: recursive call
        head->next = reverseKGroup(temp, k);
        return prev;
    }
};
