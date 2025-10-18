class Solution {
  public:
    // Function to count total nodes using Morris traversal
    int countNodes(Node* root) {
        int count = 0;
        Node* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                count++;
                curr = curr->right;
            } else {
                Node* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    count++;
                    curr = curr->right;
                }
            }
        }
        return count;
    }

    // Function to find median using Morris traversal
    float findMedian(Node* root) {
        if (!root) return 0;

        int count = countNodes(root);
        int currCount = 0;
        Node* curr = root;
        Node* prev = nullptr;
        Node* pre = nullptr;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                currCount++;

                // Odd case
                if (count % 2 != 0 && currCount == (count + 1) / 2)
                    return curr->data;

                // Even case
                else if (count % 2 == 0 && currCount == (count / 2) + 1)
                    return prev->data;

                prev = curr;
                curr = curr->right;
            } else {
                pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = nullptr;
                    prev = pre;
                    currCount++;

                    // Odd case
                    if (count % 2 != 0 && currCount == (count + 1) / 2)
                        return curr->data;

                    // Even case
                    else if (count % 2 == 0 && currCount == (count / 2) + 1)
                        return pre->data;

                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return 0.0;
    }
};
