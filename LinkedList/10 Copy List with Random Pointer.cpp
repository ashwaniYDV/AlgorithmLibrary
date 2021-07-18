// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://youtu.be/4apaOcK586U
// https://youtu.be/VNf6VynfpdM

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


// Iterative - Time = O(n), Space = O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        Node *tempNext;

        // First round:
        // make copy of each node, and link them together side-by-side in a single list.
        while (temp) {
            tempNext = temp->next;

            Node *copy = new Node(temp->val);
            temp->next = copy;
            copy->next = tempNext;

            temp = tempNext;
        }

        // Second round:
        // assign random pointers for the copy nodes.
        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Third round:
        // restore the original list, and extract the copy list.
        temp = head;
        Node *res = new Node(0);
        Node *copy = res;

        while (temp) {
            tempNext = temp->next->next;

            // extract the copy
            copy->next = temp->next;

            // restore the original list
            temp->next = tempNext;

            copy = copy -> next;
            temp = tempNext;
        }

        return res->next;
    }
};














// Recursive - Time = O(n), Space = O(n)
class Solution {
public:
    unordered_map<Node*, Node*> vis;
    
    Node* cloneList(Node* head) {
        if(!head) return head;
        if(vis[head]) return vis[head];
        
        Node* cloned = new Node(head->val);
        vis[head] = cloned;
        
        if(head->next) {
            cloned->next = cloneList(head->next);
        }
        
        return cloned;
    }

    void cloneRandom(Node* head, Node* clonedRoot) {
        if(!head) return;
        
        if(head->random) {
            clonedRoot->random =  vis[head->random];
        }
        
        cloneRandom(head->next, clonedRoot->next);
    }
    
    Node* copyRandomList(Node* head) {
        Node* cloned = cloneList(head);
        cloneRandom(head, cloned);
        return cloned;
    }
};















// Iterative - Time = O(n), Space = O(n)
class Solution {
public:
    unordered_map<Node*, Node*> vis;
    
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* cloned = new Node(head->val);
        Node *temphead = head, *tempcloned = cloned;
        vis[head] = cloned;
        
        while(temphead->next) {
            tempcloned->next = new Node(temphead->next->val);
            vis[temphead->next] = tempcloned->next;
            temphead = temphead->next;
            tempcloned = tempcloned->next;
        }
        
        temphead = head, tempcloned = cloned;
        while(temphead) {
            if(temphead->random) {
                tempcloned->random =  vis[temphead->random];
            }
            temphead = temphead->next;
            tempcloned = tempcloned->next;
        }

        return cloned;
    }
};
