class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != (int)s3.size()) return false;

        // dp[i][j] = true if first i chars of s1 and first j chars of s2
        // can interleave to form first i+j chars of s3.
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        // when j = 0, only using s1
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        // when i = 0, only using s2
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // position in s3 is i+j-1 (0-based)
                bool takeFromS1 = (s1[i-1] == s3[i+j-1]) && dp[i-1][j];
                bool takeFromS2 = (s2[j-1] == s3[i+j-1]) && dp[i][j-1];
                dp[i][j] = takeFromS1 || takeFromS2;
            }
        }

        return dp[m][n];
    }
};