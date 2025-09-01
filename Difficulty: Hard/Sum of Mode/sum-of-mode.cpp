#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;

        unordered_map<int, int> freq;              // element -> frequency
        unordered_map<int, set<int>> group;        // freq -> set of elements
        int maxFreq = 0;

        // initialize first window
        for (int i = 0; i < k; i++) {
            int x = arr[i];
            int f = ++freq[x];
            group[f].insert(x);
            if (f > 1) group[f - 1].erase(x);
            maxFreq = max(maxFreq, f);
        }
        ans += *group[maxFreq].begin();  // mode of first window

        // slide the window
        for (int i = k; i < n; i++) {
            int out = arr[i - k];
            int in = arr[i];

            // remove outgoing element
            int f = freq[out];
            group[f].erase(out);
            if (group[f].empty() && f == maxFreq) maxFreq--;
            freq[out]--;
            if (freq[out] > 0) group[freq[out]].insert(out);

            // add incoming element
            f = ++freq[in];
            group[f].insert(in);
            if (f > 1) group[f - 1].erase(in);
            maxFreq = max(maxFreq, f);

            // mode of current window
            ans += *group[maxFreq].begin();
        }

        return ans;
    }
};
