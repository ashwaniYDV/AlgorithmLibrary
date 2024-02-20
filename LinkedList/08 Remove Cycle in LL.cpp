// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// https://www.youtube.com/watch?v=aIR0s1tY2Vk


class Solution {
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (!head) return;

        Node* slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // case when cycle is at head node
                if (slow == head) {
                    while (fast->next != slow) {
                        fast = fast->next;
                    }
                    fast->next = NULL;
                    return;
                }

                slow = head;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = NULL;
            };
        }


    }
};
