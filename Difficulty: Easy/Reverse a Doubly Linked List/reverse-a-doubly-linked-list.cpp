class Solution {
  public:
    Node *reverse(Node *head) {
        if (!head || !head->next) return head;  // empty or single node list
        
        Node* curr = head;
        Node* temp = nullptr;
        
        // Traverse the list and swap next and prev for each node
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;  // move to the next node (which is prev now)
        }
        
        // After the loop, temp points to the new head’s previous node
        if (temp) {
            head = temp->prev;
        }
        
        return head;
    }
};
