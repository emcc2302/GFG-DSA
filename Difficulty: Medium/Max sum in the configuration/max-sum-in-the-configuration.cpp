class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        
        long long totalSum = 0;
        long long currVal = 0;
        
        // Compute total sum and initial weighted sum
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
            currVal += 1LL * i * arr[i];
        }
        
        long long ans = currVal;
        
        // Compute values for other rotations
        for (int i = 1; i < n; i++) {
            currVal = currVal + totalSum - 1LL * n * arr[n - i];
            ans = max(ans, currVal);
        }
        
        return (int)ans;
    }
};
