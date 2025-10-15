/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

#include <stack>
#include <iostream>

class Solution {
public:
    /**
     * Finds the k-th smallest element in a Binary Search Tree (BST).
     * @param root The root of the BST.
     * @param k The desired rank (1-based) of the smallest element.
     * @return The value of the k-th smallest element, or -1 if it doesn't exist.
     */
    int kthSmallest(Node *root, int k) {
        if (!root || k <= 0) {
            return -1;
        }

        std::stack<Node*> s;
        Node* current = root;
        int count = 0;

        // Perform Iterative Inorder Traversal
        while (current != NULL || !s.empty()) {
            
            // 1. Traverse to the leftmost node, pushing all nodes onto the stack
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }

            // 2. Pop the next smallest element (the one at the top of the stack)
            current = s.top();
            s.pop();

            // 3. Process the node (this is the core 'visit' step of Inorder)
            count++;

            // Check if this is the k-th smallest element
            if (count == k) {
                return current->data;
            }

            // 4. Move to the right subtree to find the next smallest elements
            current = current->right;
        }

        // If the loop finishes but count < k, it means k is larger than the total number of nodes.
        return -1;
    }
};