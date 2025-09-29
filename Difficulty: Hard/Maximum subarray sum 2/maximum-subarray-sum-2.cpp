#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }

        multiset<long long> window; 
        long long ans = LLONG_MIN;

        for (int r = a; r <= n; r++) {
            // Add candidate l = r - a
            window.insert(pref[r - a]);

            // Remove invalid l < r - b
            if (r - b - 1 >= 0) {
                window.erase(window.find(pref[r - b - 1]));
            }

            // Best subarray ending at r-1
            ans = max(ans, pref[r] - *window.begin());
        }

        return (int)ans;
    }
};
