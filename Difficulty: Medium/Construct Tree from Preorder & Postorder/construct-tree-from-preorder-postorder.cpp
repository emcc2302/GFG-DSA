class Solution {
  public:
    int idx = 0;
    Node* constructTreeUtil(vector<int>& pre, vector<int>& post, int l, int r) {
        if (idx >= pre.size() || l > r)
            return nullptr;
        
        Node* root = new Node(pre[idx++]);
        
        // If it's a leaf node
        if (l == r || idx >= pre.size())
            return root;
        
        // Find next preorder element in postorder to split left/right subtrees
        int i;
        for (i = l; i <= r; i++) {
            if (post[i] == pre[idx])
                break;
        }
        
        if (i <= r) {
            root->left = constructTreeUtil(pre, post, l, i);
            root->right = constructTreeUtil(pre, post, i + 1, r - 1);
        }
        
        return root;
    }
    
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        idx = 0;
        return constructTreeUtil(pre, post, 0, post.size() - 1);
    }
};
