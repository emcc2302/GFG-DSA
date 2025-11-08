class Solution {
public:
    int dp[101][101][101];

    int solve(vector<vector<int>>& mat, int i, int j, int k) {
        if (i < 0 || j < 0) return 0;   
        if (k < 0) return 0;   

        if (i == 0 && j == 0) {
            return (mat[0][0] == k) ? 1 : 0;  
        }

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int left = solve(mat, i, j - 1, k - mat[i][j]);
        int up = solve(mat, i - 1, j, k - mat[i][j]);

        return dp[i][j][k] = left + up;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(mat, n - 1, m - 1, k);
    }
};
