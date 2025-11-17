class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dp(n);

        // Each element itself is an increasing subsequence
        for(int i = 0; i < n; i++)
            dp[i] = arr[i];

        // Build dp[] such that dp[i] stores
        // max sum of increasing subsequence ending at i
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        // Answer is the maximum value in dp[]
        int ans = 0;
        for(int x : dp) ans = max(ans, x);

        return ans;
    }
};
