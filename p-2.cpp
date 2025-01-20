#include <iostream>
using namespace std;

// Definition for a Node.
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* p = head, *nxt;
        
        while (p) {
            // If the current node has a child, flatten the child list
            if (p->child) {
                nxt = p->next; // Store the next node
                
                // Flatten the child list and link it to the current node
                p->next = flatten(p->child); // Flatten the child recursively
                p->child = nullptr; // Set the child pointer to null since it's flattened
                
                // Set the prev pointer of the newly linked child list
                p->next->prev = p;
                
                // Move to the last node of the flattened child list
                while (p->next) {
                    p = p->next;
                }
                
                // Attach the original next node, if any, to the last node
                p->next = nxt;
                if (nxt) {
                    nxt->prev = p;
                }

            } else {
                // Move to the next node if no child is present
                p = p->next;
            }
        }
        
        return head;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new node
Node* createNode(int val) {
    return new Node(val);
}

// Test the solution
int main() {
    // Creating a test case with a multi-level doubly linked list
    
    // Level 0 (Main List): 1 - 2 - 3 - 4 - 5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    // Adding children for some nodes
    head->next->child = createNode(6); // Node 2 has a child 6
    head->next->next->child = createNode(7); // Node 3 has a child 7

    // Flatten the list
    Solution solution;
    Node* flattenedHead = solution.flatten(head);

    // Print the flattened list
    printList(flattenedHead);

    return 0;
}
