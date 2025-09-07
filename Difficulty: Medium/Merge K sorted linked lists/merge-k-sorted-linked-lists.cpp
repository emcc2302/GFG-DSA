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

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to merge two sorted linked lists
    Node* mergeTwoLists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy->next;
    }

    // Function to merge k sorted linked lists
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return NULL;

        int last = arr.size() - 1;

        // Repeat until only one list is left
        while (last != 0) {
            int i = 0, j = last;

            // Merge pairs of lists
            while (i < j) {
                arr[i] = mergeTwoLists(arr[i], arr[j]);
                i++;
                j--;

                // All pairs merged, update last
                if (i >= j) last = j;
            }
        }

        return arr[0];
    }
};
