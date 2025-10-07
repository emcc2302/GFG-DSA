class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if (!root) return {};
        map<int, int> mp; // {hd, node->data}
        queue<pair<Node*, int>> q; // {node, hd}
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, hd] = q.front(); 
            q.pop();
            mp[hd] = node->data;  // update latest (bottom-most)
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        vector<int> ans;
        for (auto &it : mp) ans.push_back(it.second);
        return ans;
    }
};
