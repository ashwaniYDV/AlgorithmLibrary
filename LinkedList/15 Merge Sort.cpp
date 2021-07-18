// https://www.scaler.com/problems/sort-list/

/*
Sort a linked list, A in O(n log n) time using constant space complexity.
*/



// C++
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode * head = NULL; // head of the list to return
    // find first element (can use dummy node to put this part inside of the loop)
    if (l1 -> val < l2 -> val) {
        head = l1;
        l1 = l1 -> next;
    } else {
        head = l2;
        l2 = l2 -> next;
    }
    ListNode * p = head; // pointer to form new list
    while (l1 && l2) {
        if (l1 -> val < l2 -> val) {
            p -> next = l1;
            l1 = l1 -> next;
        } else {
            p -> next = l2;
            l2 = l2 -> next;
        }
        p = p -> next;
    }
    // add the rest of the tail, done!
    if (l1) {
        p -> next = l1;
    } else {
        p -> next = l2;
    }
    return head;
}

ListNode * Solution::sortList(ListNode * head) {
    if (head == NULL || head -> next == NULL)
        return head;
    // find the middle place
    ListNode * p1 = head;
    ListNode * p2 = head -> next;
    while (p2 && p2 -> next) {
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }
    p2 = p1 -> next;
    p1 -> next = NULL;

    return mergeTwoLists(sortList(head), sortList(p2));
}









// Java
public class Solution {
    public ListNode sortList(ListNode A) {
        if (A == null || A.next == null)
            return A;
        ListNode first = A;
        ListNode second = findMidNode(A);
        first = sortList(first);
        second = sortList(second);
        ListNode res = mergeNodes(first, second);
        return res;

    }

    public ListNode mergeNodes(ListNode node1, ListNode node2) {
        ListNode dummy = new ListNode(0);
        ListNode head = dummy;
        while (node1 != null && node2 != null) {
            if (node1.val <= node2.val) {
                dummy.next = node1;
                node1 = node1.next;
            } else {
                dummy.next = node2;
                node2 = node2.next;
            }
            dummy = dummy.next;
        }
        dummy = addNodes(dummy, node1);
        addNodes(dummy, node2);
        head = head.next;
        return head;
    }

    public ListNode addNodes(ListNode node, ListNode node1) {
        while (node1 != null) {
            node.next = node1;
            node1 = node1.next;
            node = node.next;
        }
        return node;
    }

    public ListNode findMidNode(ListNode node) {
        ListNode doubleRate;
        ListNode prev;
        if (node == null || node.next == null)
            return node;
        doubleRate = node;
        prev = node;
        while (doubleRate.next != null && doubleRate.next.next != null) {
            prev = node;
            node = node.next;
            doubleRate = doubleRate.next.next;
        }
        prev = node;
        node = node.next;
        prev.next = null;
        return node;
    }
}
