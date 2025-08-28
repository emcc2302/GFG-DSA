class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, zeroCount = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (arr[right] == 0) zeroCount++;

            while (zeroCount > k) {
                if (arr[left] == 0) zeroCount--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
