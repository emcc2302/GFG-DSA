class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        // Step 1: Count total nodes in the list
        Node* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Step 2: Reverse in groups of k (including last smaller group)
        curr = head;
        while (length > 0) {
            int toReverse = (length >= k ? k : length); // size of current group
            Node* groupPrev = prev;
            Node* groupEnd = curr;

            // Reverse 'toReverse' nodes
            Node* groupPrevNext = next;
            prev = NULL;
            for (int i = 0; i < toReverse; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous part with current reversed group
            if (groupPrev) {
                groupPrev->next = prev;
            } else {
                head = prev; // first group reversed, update head
            }

            groupEnd->next = curr;
            prev = groupEnd;
            length -= toReverse;
        }

        return head;
    }
};
