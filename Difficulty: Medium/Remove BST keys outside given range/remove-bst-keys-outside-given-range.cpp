class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // base case
        if (!root) return NULL;
        
        // first, fix left and right subtrees
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        // if current node's data is less than l
        if (root->data < l) {
            Node* rightChild = root->right;
            delete root; // free memory
            return rightChild;
        }
        
        // if current node's data is greater than r
        if (root->data > r) {
            Node* leftChild = root->left;
            delete root; // free memory
            return leftChild;
        }
        
        // current node is in range
        return root;
    }
};
