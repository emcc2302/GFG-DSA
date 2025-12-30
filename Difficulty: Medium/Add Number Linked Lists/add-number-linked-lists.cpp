/* 
  Node structure provided by problem:
  class Node {
    public:
      int data;
      Node* next;
      Node(int x) {
          data = x;
          next = NULL;
      }
  };
*/

class Solution {
  private:
    // Reverse linked list
    Node* reverse(Node* head) {
      Node* prev = NULL;
      Node* curr = head;
      while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
      }
      return prev;
    }

    // Remove leading zeros
    Node* trimLeadingZeros(Node* head) {
      while (head && head->data == 0 && head->next) {
        head = head->next;
      }
      return head;
    }

  public:
    Node* addTwoLists(Node* head1, Node* head2) {
      // Trim inputs
      head1 = trimLeadingZeros(head1);
      head2 = trimLeadingZeros(head2);

      // Reverse lists so we add from LSD
      head1 = reverse(head1);
      head2 = reverse(head2);

      int carry = 0;
      Node* result = NULL;

      // Add corresponding digits
      while (head1 || head2 || carry) {
        int v1 = (head1 ? head1->data : 0);
        int v2 = (head2 ? head2->data : 0);

        int sum = v1 + v2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        // Create new node for this digit
        Node* newNode = new Node(digit);
        newNode->next = result;
        result = newNode;

        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
      }

      // Result is already in forward order
      return result;
    }
};
