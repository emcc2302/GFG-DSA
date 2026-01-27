class Solution {
  public:
    bool dfs(int i, int j, int idx, vector<vector<char>> &mat, string &word,
             vector<vector<int>> &vis) {

        int n = mat.size();
        int m = mat[0].size();

        // matched full word
        if (idx == (int)word.size()) return true;

        // out of bound or already used or mismatch
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        if (vis[i][j] == 1) return false;
        if (mat[i][j] != word[idx]) return false;

        vis[i][j] = 1;

        // 4 directions
        bool found =
            dfs(i + 1, j, idx + 1, mat, word, vis) ||
            dfs(i - 1, j, idx + 1, mat, word, vis) ||
            dfs(i, j + 1, idx + 1, mat, word, vis) ||
            dfs(i, j - 1, idx + 1, mat, word, vis);

        vis[i][j] = 0; // backtrack
        return found;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (dfs(i, j, 0, mat, word, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
