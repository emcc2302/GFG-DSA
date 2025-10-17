class Solution {
  public:
    int sum = 0; // to keep track of sum of greater nodes
    
    void transformTree(Node* root) {
        if (!root) return;
        
        // Step 1: traverse right (greater values first)
        transformTree(root->right);
        
        // Step 2: store the original value
        int temp = root->data;
        
        // Step 3: update current node data with current sum
        root->data = sum;
        
        // Step 4: add the original value to sum
        sum += temp;
        
        // Step 5: traverse left subtree
        transformTree(root->left);
    }
};
