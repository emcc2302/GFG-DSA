class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Prefix sum for quick subarray sum queries
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + freq[i];
        }
        
        auto getSum = [&](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };
        
        // l = length of interval
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                
                if (i == j) {
                    dp[i][j] = freq[i];
                    continue;
                }

                dp[i][j] = INT_MAX;
                int totalFreq = getSum(i, j);

                for (int root = i; root <= j; root++) {
                    int left  = (root > i) ? dp[i][root - 1] : 0;
                    int right = (root < j) ? dp[root + 1][j] : 0;

                    dp[i][j] = min(dp[i][j], left + right + totalFreq);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
