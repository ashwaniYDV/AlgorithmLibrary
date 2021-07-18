// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

/*
Implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
*/



// Method 1: Using 2 doubly linkedlists

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    list<int> left, right;

    MyStack() {
    };

    void reshuffle() {
        if (right.size() > left.size() + 1) {
            int x = *right.begin();
            right.pop_front();
            left.push_back(x);
        }
        if (left.size() > right.size()) {
            int x = *left.rbegin();
            left.pop_back();
            right.push_front(x);
        }
    }

    void printDLL() {
        for (auto it : left) {
            cout << it << " -> ";
        }
        for (auto it : right) {
            cout << it << " -> ";
        }
        cout << endl << endl;
    }

    // adds elements at the ending of right doubly linkedlist
    void push(int data) {
        right.push_back(data);
        reshuffle();
    }

    int pop() {
        /* Stack underflow */
        if (right.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        int value = *right.rbegin();
        right.pop_back();

        reshuffle();

        return value;
    }

    int findMiddle() {
        if (right.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return *right.begin();
    }

    int deletemiddle() {
        if (right.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        int midValue = *right.begin();
        right.pop_front();

        reshuffle();

        return midValue;
    }
};

int main() {
    MyStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);

    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Item popped = " << st.pop() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();
    return 0;
}

/*
11 -> 22 -> 33 -> 44 -> 55 -> 

Middle Element = 33
Deleted Middle Element = 33
11 -> 22 -> 44 -> 55 -> 

Item popped = 55
11 -> 22 -> 44 -> 

Middle Element = 22
Deleted Middle Element = 22
11 -> 44 -> 

Middle Element = 44
Deleted Middle Element = 44
11 -> 

Middle Element = 11
Deleted Middle Element = 11


Middle Element = Stack is empty!
-1
Deleted Middle Element = Stack is empty!
-1

*/


























// Method 2.1

#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class DLLNode {
public:
    int data;
    DLLNode *prev, *next;
    DLLNode(int d) {
        data = d;
        prev = next = NULL;
    }
};

/* Representation of the stack data structure that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node and middle node and count of nodes */
class MyStack {
public:
    DLLNode *head, *mid;
    int count;

    MyStack() {
        count = 0;
        head = mid = NULL;
    };

    void printDLL() {
        DLLNode *tmp = head;
        while (tmp) {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << endl << endl;
    }

    // adds elements at the beginning of doubly linkedlist
    void push(int data) {
        DLLNode* node = new DLLNode(data);

        /* Since we are adding at the beginning, prev is always NULL */
        node->prev = NULL;

        /* link the old list off the new DLLNode */
        node->next = head;

        /* Increment count of items in stack */
        count += 1;

        /* Change mid pointer in two cases
        1) Linked List is empty
        2) Number of nodes in linked list is odd */
        if (count == 1) {
            mid = node;
        } else {
            head->prev = node;

            // Update mid if count is even
            if (!(count & 1)) {
                mid = mid->prev;
            }
        }

        /* move head to point to the new DLLNode */
        head = node;
    }

    int pop() {
        /* Stack underflow */
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }

        DLLNode* tempHead = head;
        int headValue = head->data;
        head = head->next;

        // If linked list doesn't become empty, update prev of new head as NULL
        if (head != NULL) {
            head->prev = NULL;
        }

        count--;

        // update the mid pointer when we have odd number of elements in the stack,
        //i,e move down the mid pointer.
        if ((count) & 1) {
            mid = mid->next;
        }

        delete tempHead;
        return headValue;
    }

    int findMiddle() {
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return mid->data;
    }

    int deletemiddle() {
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        if (count == 1) {
            int midValue = mid->data;
            count = 0;

            delete mid;
            head = mid = NULL;
            return midValue;
        }
        if (count == 2) {
            int midValue = mid->data;
            count = 1;

            head = mid->next;
            head->prev = head->next = NULL;
            delete mid;
            mid = head;
            return midValue;
        }

        int midValue = mid->data;
        DLLNode *tempMid = mid;
        mid->prev->next = tempMid->next;
        mid->next->prev = tempMid->prev;

        count--;
        if (count % 2 == 0) {
            mid = tempMid->prev;
        } else {
            mid = tempMid->next;
        }
        delete tempMid;
        return midValue;
    }
};

int main() {
    MyStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);

    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Item popped = " << st.pop() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();
    return 0;
}


/*
55 -> 44 -> 33 -> 22 -> 11 -> 

Middle Element = 33
Deleted Middle Element = 33
55 -> 44 -> 22 -> 11 -> 

Item popped = 55
44 -> 22 -> 11 -> 

Middle Element = 22
Deleted Middle Element = 22
44 -> 11 -> 

Middle Element = 44
Deleted Middle Element = 44
11 -> 

Middle Element = 11
Deleted Middle Element = 11


Middle Element = Stack is empty!
-1
Deleted Middle Element = Stack is empty!
-1

*/























// Method 2.2

#include <bits/stdc++.h>
using namespace std;


class MyStack {
public:
    list<int> arr;
    list<int>::iterator mid;
    int count;

    MyStack() {
        count = 0;
    };

    void printDLL() {
        for (auto it : arr) {
            cout << it << " -> ";
        }
        cout << endl << endl;
    }

    // adds elements at the beginning of doubly linkedlist
    void push(int data) {
        arr.push_front(data);

        /* Increment count of items in stack */
        count += 1;

        /* Change mid pointer in two cases
        1) Linked List is empty
        2) Number of nodes in linked list is odd */
        if (count == 1) {
            mid = arr.begin();
        } else {
            // Update mid if count is even
            if (!(count & 1)) {
                mid = prev(mid);
            }
        }
    }

    int pop() {
        /* Stack underflow */
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }

        int value = *arr.begin();
        arr.pop_front();

        count--;

        // update the mid pointer when we have odd number of elements in the stack,
        // i,e move down the mid pointer.
        if ((count) & 1) {
            mid = next(mid);
        }

        return value;
    }

    int findMiddle() {
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return *mid;
    }

    int deletemiddle() {
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        if (count == 1) {
            int midValue = *mid;
            count = 0;
            arr.erase(mid);
            return midValue;
        }
        if (count == 2) {
            int midValue = *mid;
            count = 1;

            arr.erase(mid);
            mid = arr.begin();
            return midValue;
        }

        int midValue = *mid;
        list<int>::iterator tempMid;

        count--;
        if (count % 2 == 0) {
            tempMid = prev(mid);
        } else {
            tempMid = next(mid);
        }

        arr.erase(mid);
        mid = tempMid;
        return midValue;
    }
};

int main() {
    MyStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);

    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Item popped = " << st.pop() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();
    return 0;
}

/*
55 -> 44 -> 33 -> 22 -> 11 -> 

Middle Element = 33
Deleted Middle Element = 33
55 -> 44 -> 22 -> 11 -> 

Item popped = 55
44 -> 22 -> 11 -> 

Middle Element = 22
Deleted Middle Element = 22
44 -> 11 -> 

Middle Element = 44
Deleted Middle Element = 44
11 -> 

Middle Element = 11
Deleted Middle Element = 11


Middle Element = Stack is empty!
-1
Deleted Middle Element = Stack is empty!
-1

*/




















// Method 3

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    list<int> arr;
    list<int>::iterator mid;
    int count;

    MyStack() {
        count = 0;
    };

    void printDLL() {
        for (auto it : arr) {
            cout << it << " -> ";
        }
        cout << endl << endl;
    }

    // adds elements at the ending of doubly linkedlist
    void push(int data) {
        arr.push_back(data);

        /* Increment count of items in stack */
        count += 1;

        /* Change mid pointer in two cases
        1) Linked List is empty
        2) Number of nodes in linked list is odd */
        if (count == 1) {
            mid = arr.begin();
        } else {
            // Update mid if count is even
            if (!(count & 1)) {
                mid = next(mid);
            }
        }
    }

    int pop() {
        /* Stack underflow */
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }

        int value = *arr.rbegin();
        arr.pop_back();

        count--;

        // update the mid pointer when we have odd number of elements in the stack,
        // i,e move down the mid pointer.
        if ((count) & 1) {
            mid = prev(mid);
        }

        return value;
    }

    int findMiddle() {
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return *mid;
    }

    int deletemiddle() {
        if (count == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        if (count == 1) {
            int midValue = *mid;
            count = 0;
            arr.erase(mid);
            return midValue;
        }
        if (count == 2) {
            int midValue = *mid;
            count = 1;

            arr.erase(mid);
            mid = arr.begin();
            return midValue;
        }

        int midValue = *mid;
        list<int>::iterator tempMid;

        count--;
        if (count % 2 == 0) {
            tempMid = next(mid);
        } else {
            tempMid = prev(mid);
        }

        arr.erase(mid);
        mid = tempMid;
        return midValue;
    }
};

int main() {
    MyStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);

    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Item popped = " << st.pop() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    st.printDLL();
    return 0;
}

/*
11 -> 22 -> 33 -> 44 -> 55 -> 

Middle Element = 33
Deleted Middle Element = 33
11 -> 22 -> 44 -> 55 -> 

Item popped = 55
11 -> 22 -> 44 -> 

Middle Element = 22
Deleted Middle Element = 22
11 -> 44 -> 

Middle Element = 44
Deleted Middle Element = 44
11 -> 

Middle Element = 11
Deleted Middle Element = 11


Middle Element = Stack is empty!
-1
Deleted Middle Element = Stack is empty!
-1

*/
