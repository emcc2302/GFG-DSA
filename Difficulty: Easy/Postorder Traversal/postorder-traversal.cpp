class Solution {
  public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        
        stack<Node*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);
            
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        
        while (!s2.empty()) {
            ans.push_back(s2.top()->data);
            s2.pop();
        }
        
        return ans;
    }
};
