#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n-1] - arr[0];

        for (int i = 0; i < n - 1; i++) {
            int high = max(arr[i] + k, arr[n-1] - k);
            int low  = min(arr[0] + k, arr[i+1] - k);

            if (low < 0) continue; // skip invalid case

            ans = min(ans, high - low);
        }

        return ans;
    }
};
