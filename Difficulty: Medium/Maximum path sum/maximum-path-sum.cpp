class Solution {
  public:
    int findMaxSum(Node *root) {
        int globalMax = INT_MIN;
        dfs(root, globalMax);
        return globalMax;
    }
  
  private:
    // Returns maximum downward path sum starting at node
    int dfs(Node *node, int &globalMax) {
        if (node == nullptr) {
            return 0;
        }
        // Recurse on left and right
        int leftGain = max(0, dfs(node->left, globalMax));
        int rightGain = max(0, dfs(node->right, globalMax));
        
        // Consider path through this node
        int priceNewPath = node->data + leftGain + rightGain;
        
        // Update global max if current path is better
        globalMax = max(globalMax, priceNewPath);
        
        // Return best contribution to parent
        return node->data + max(leftGain, rightGain);
    }
};
