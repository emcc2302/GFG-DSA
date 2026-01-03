/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        vector<int> values;

    // Push values of all nodes into an array
    while (root != nullptr) {

        // Push the head node of the sub-linked-list
        values.push_back(root->data);

        // Push all the nodes of the sub-linked-list
        Node* temp = root->bottom;
        while (temp != nullptr) {
            values.push_back(temp->data);
            temp = temp->bottom;
        }

        // Move to the next head node
        root = root->next;
    }

    // Sort the node values in ascending order
    sort(values.begin(), values.end());

    // Construct the new flattened linked list
    Node* tail = nullptr;
    Node* head = nullptr;
    for (int i = 0; i < values.size(); i++) {
        Node* newNode = new Node(values[i]);

        // If this is the first node of the linked list,
        // make the node as head
        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->bottom = newNode;
        }
        tail = newNode;
    }
    return head;
    }
};