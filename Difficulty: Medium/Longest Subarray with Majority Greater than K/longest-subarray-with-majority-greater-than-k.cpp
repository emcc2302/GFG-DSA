class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> diff(n);
        
        for (int i = 0; i < n; ++i) {
            diff[i] = (arr[i] > k) ? 1 : -1;
        }

        unordered_map<int, int> firstIndex;
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += diff[i];

            if (prefixSum > 0) {
                maxLen = i + 1;
            } else {
                if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                    maxLen = max(maxLen, i - firstIndex[prefixSum - 1]);
                }
            }

            if (firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
