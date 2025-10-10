class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                // Find position to fill in the level vector
                int index = leftToRight ? i : size - i - 1;
                level[index] = node->data;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Append this level's result to the final answer
            for (int x : level) ans.push_back(x);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
