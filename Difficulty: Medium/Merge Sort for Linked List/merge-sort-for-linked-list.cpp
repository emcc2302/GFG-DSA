/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result = nullptr;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    
    // Function to find the middle of the linked list
    Node* getMiddle(Node* head) {
        if (!head) return head;
        
        Node* slow = head;
        Node* fast = head->next;  // fast starts ahead to split correctly
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Main mergeSort function
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;  // base case
        
        // Get middle node
        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;
        
        // Split the linked list into two halves
        middle->next = nullptr;
        
        // Recursively sort the two halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);
        
        // Merge the sorted halves
        return merge(left, right);
    }
};
