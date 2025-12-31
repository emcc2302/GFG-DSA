/*
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
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node *t1 = head1, *t2 = head2;
        while(t1 != t2){
            t1 = t1 ? t1->next : head2;
            t2 = t2 ? t2->next : head1;
        }
        return t1;
    }
};