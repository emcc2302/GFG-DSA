class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count of missing numbers till index mid
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // kth missing number
        return low + k;
    }
};
