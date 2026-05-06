class Solution {
public:

int getSize(Node* root) {
    // Base Case
    if(!root) {
        return 0;
    }
    
    // Recursion call to left & right
    int ans = 1 + getSize(root->left) + getSize(root->right);
    
    return ans;
}

};