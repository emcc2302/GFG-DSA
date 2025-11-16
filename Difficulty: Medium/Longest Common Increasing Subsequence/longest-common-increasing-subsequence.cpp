class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m, 0); // dp[j] = LCIS ending at b[j]
        
        for(int i = 0; i < n; i++) {
            int best = 0; 
            for(int j = 0; j < m; j++) {
                
                if(a[i] > b[j]) {
                    // candidate for extending
                    best = max(best, dp[j]);
                }

                else if(a[i] == b[j]) {
                    // we can extend a previous best
                    dp[j] = best + 1;
                }
            }
        }
        
        // max value in dp[] is our answer
        return *max_element(dp.begin(), dp.end());
    }
};
