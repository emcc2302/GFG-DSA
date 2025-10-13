class Solution {
  pair<long long, long long> dfs(Node* root) {
    // returns {inc, exc}
    if (!root) {
      return {0, 0};
    }
    auto L = dfs(root->left);
    auto R = dfs(root->right);

    long long inc_u = root->data + L.second + R.second;
    long long exc_u = max(L.first, L.second) + max(R.first, R.second);

    return {inc_u, exc_u};
  }

public:
  int getMaxSum(Node *root) {
    auto res = dfs(root);
    long long ans = max(res.first, res.second);
    // If they expect int, cast (but careful about overflow if sums exceed int range)
    return (int)ans;
  }
};
