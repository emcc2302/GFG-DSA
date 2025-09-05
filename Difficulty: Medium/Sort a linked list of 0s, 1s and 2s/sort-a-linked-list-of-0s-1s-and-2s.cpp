class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Dummy nodes
        Node zeroDummy(0), oneDummy(0), twoDummy(0);
        Node *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;

        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Merge lists: 0s → 1s → 2s
        zero->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr;

        return zeroDummy.next;
    }
};
