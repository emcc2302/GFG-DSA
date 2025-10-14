class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (root == NULL) return 0;

        // If current node's value is less than l, only right subtree can have valid nodes
        if (root->data < l) {
            return nodeSum(root->right, l, r);
        }

        // If current node's value is greater than r, only left subtree can have valid nodes
        if (root->data > r) {
            return nodeSum(root->left, l, r);
        }

        // If current node lies within [l, r], include it and explore both sides
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};
