class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Sum of first window
        int windowSum = 0;
        for(int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        
        int maxSum = windowSum;
        
        // Slide the window
        for(int i = k; i < n; i++) {
            windowSum = windowSum + arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
    }
};
