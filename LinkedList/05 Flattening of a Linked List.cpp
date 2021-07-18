// https://www.geeksforgeeks.org/flattening-a-linked-list/
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://youtu.be/ysytSSXpAI0


/*
Given a linked list where every node represents a linked list and contains two pointers of its type: 
a) next = Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
b) bottom = Pointer to a linked list where this node is headed (we call it the ‘bottom’ pointer in the code below). 
All linked lists are sorted. See the following example  

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. 
For example, for the above input list, output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50. 
*/




/* Node structure  used in the program
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

// Method 1

Node* mergeTwoLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data > l2->data) std::swap(l1, l2);

    Node *res = l1;

    while (l1 && l2) {
        Node *temp = NULL;
        while (l1 && l1->data <= l2->data) {
            temp = l1;
            l1 = l1->bottom;
        }
        temp->bottom = l2;
        swap(l1, l2);
    }

    return res;
}

// Main function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    if (!root || !root->next) return root;

    // recur for list on right
    root->next = flatten(root->next);

    // merge the current node and the right part
    root = mergeTwoLists(root, root->next);

    return root;
}




















// Method 2

Node *mergeTwoLists(Node *a, Node *b) {
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(a && b) {
        if(a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    if(a) temp->bottom = a;
    else temp->bottom = b;
    
    return res->bottom;
}

// Main function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    if(!root || !root->next) return root;
    
    // recur for list on right
    root->next = flatten(root->next);
    
    // merge the current node and the right part
    root = mergeTwoLists(root, root->next);
    
    return root;
}
