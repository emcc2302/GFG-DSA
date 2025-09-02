class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Find length of list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: If k > n, no swap
        if (k > n) return head;

        // Step 3: If kth from start == kth from end (same node)
        if (2 * k - 1 == n) return head;

        // Step 4: Find kth node from start
        Node* x_prev = nullptr;
        Node* x = head;
        for (int i = 1; i < k; i++) {
            x_prev = x;
            x = x->next;
        }

        // Step 5: Find kth node from end
        Node* y_prev = nullptr;
        Node* y = head;
        for (int i = 1; i < n - k + 1; i++) {
            y_prev = y;
            y = y->next;
        }

        // Step 6: Swap nodes
        if (x_prev) x_prev->next = y;
        if (y_prev) y_prev->next = x;

        Node* temp_next = x->next;
        x->next = y->next;
        y->next = temp_next;

        // Step 7: Update head if needed
        if (k == 1) head = y;
        else if (k == n) head = x;

        return head;
    }
};
