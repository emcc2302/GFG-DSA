class Solution {
public:
    bool canMake(vector<int>& arr, int k, int m, int day) {
        int bouquets = 0, flowers = 0;
        for (int bloom : arr) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;  // reset after making a bouquet
                }
            } else {
                flowers = 0; // reset because they must be adjacent
            }
        }
        return bouquets >= m;
    }
    
    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long totalNeeded = 1LL * m * k;
        if (arr.size() < totalNeeded) return -1;
        
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1; // try smaller day
            } else {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};
