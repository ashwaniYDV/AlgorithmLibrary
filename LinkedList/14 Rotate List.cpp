// https://leetcode.com/problems/rotate-list/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        
        int cnt = 0;
        ListNode *temp = head, *prev1 = NULL, *prev2 = NULL;
        
        while(temp) {
            prev1 = temp;
            temp = temp->next;
            cnt++;
        }
        // to handle case when k > cnt (Example cnt = 3, k = 4);
        k = k % cnt;
        if(k == 0) return head;
        
        int ct = cnt - k;
        temp = head;
        while(ct--) {
            prev2 = temp;
            temp = temp->next;
        }
        
        prev1->next = head;
        prev2->next = NULL;
        
        return temp;
    }
};
