class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        // Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(0, m - 1, cuts, dp);
    }

    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (j - i <= 1) return 0; // No cuts possible inside interval

        if (dp[i][j] != -1) return dp[i][j];

        int cost = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            cost = min(cost,
                       (cuts[j] - cuts[i]) +
                       solve(i, k, cuts, dp) +
                       solve(k, j, cuts, dp));
        }

        return dp[i][j] = cost;
    }
};
