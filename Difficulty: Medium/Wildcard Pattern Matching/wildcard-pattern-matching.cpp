class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        bool dp[n + 1][m + 1];
        
        // initialize dp table
        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
            dp[0][i] = (pat[i - 1] == '*') ? dp[0][i - 1] : false;
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;
        
        // fill dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == txt[i - 1] || pat[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pat[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};
