class Solution {
  public:
    bool canAchieve(vector<int> &arr, int k, int w, int target) {
        int n = arr.size();
        vector<long long> diff(n + 1, 0);
        long long add = 0, used = 0;

        for (int i = 0; i < n; i++) {
            add += diff[i];
            long long cur = arr[i] + add;

            if (cur < target) {
                long long need = target - cur;
                used += need;
                if (used > k) return false;

                add += need;
                if (i + w < n) diff[i + w] -= need;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;  

        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
