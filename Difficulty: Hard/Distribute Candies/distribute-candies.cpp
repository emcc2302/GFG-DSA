class Solution {
  public:
    int moves = 0;

    int dfs(Node* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        moves += abs(left) + abs(right); // each transfer counts as a move
        return root->data + left + right - 1; // net balance
    }

    int distCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
