class Solution {
  public:
    int derangeCount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;

        vector<int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};