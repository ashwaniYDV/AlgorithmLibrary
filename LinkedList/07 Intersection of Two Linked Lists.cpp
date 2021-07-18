// https://leetcode.com/problems/intersection-of-two-linked-lists/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        ListNode *a = headA, *b = headB;
        
        // if a and b have different length than we'll stop the loop after second iteration
        while(a != b) {
            // for the end of first iteration, we just reset the pointer to the head of another linkedlist 
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        
        return a;
    }      
};





 
 // Not memory efficient - O(n) extra memory
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mp;
        while(headA) {
            mp[headA]++;
            headA = headA->next;
        }
        while(headB) {
            if(mp[headB]) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempa = headA, *tempb = headB;
        int sizea = 0, sizeb = 0;
        
        while(tempa) {
            sizea++;
            tempa = tempa->next;
        }
        while(tempb) {
            sizeb++;
            tempb = tempb->next;
        }
        
        if(sizea < sizeb) {
            swap(sizea, sizeb);
            swap(headA, headB);
        }
        int diff = sizea - sizeb;
        
        while(diff--) {
            headA = headA->next;
        }
        
        while(sizeb--) {
            if(headA == headB) return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }      
};
