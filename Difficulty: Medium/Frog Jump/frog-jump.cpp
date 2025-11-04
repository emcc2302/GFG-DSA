class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;

        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {
            int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
            int jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(jumpOne, jumpTwo);
        }

        return dp[n - 1];
    }
};
