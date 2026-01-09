class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int left = 0;
        int distinct = 0;
        long long count = 0;

        for (int right = 0; right < n; right++) {
            if (freq[arr[right]] == 0) {
                distinct++;
            }
            freq[arr[right]]++;

            while (distinct > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    distinct--;
                }
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};
