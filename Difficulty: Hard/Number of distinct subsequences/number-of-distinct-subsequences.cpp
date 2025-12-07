class Solution {
public:
    int distinctSubseq(string &str) {
        const int MOD = 1e9 + 7;
        int n = str.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  // empty subsequence

        vector<int> last(26, -1);  // last occurrence of each character

        for (int i = 0; i < n; i++) {
            int c = str[i] - 'a';

            // double the subsequences
            dp[i + 1] = (2 * dp[i]) % MOD;

            // subtract old contribution if character repeated
            if (last[c] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[c]] + MOD) % MOD;
            }

            // update last occurrence
            last[c] = i;
        }

        return dp[n];
    }
};
