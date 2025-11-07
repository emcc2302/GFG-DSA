#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();

        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        // DP array: dp[i] = max profit until i-th job
        vector<int> dp(n, 0);
        dp[0] = jobs[0][2];

        // Extract end times for binary search
        vector<int> endTimes;
        for (auto &job : jobs)
            endTimes.push_back(job[1]);

        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i][2];

            // Find last non-overlapping job using binary search
            int idx = upper_bound(endTimes.begin(), endTimes.end(), jobs[i][0]) - endTimes.begin() - 1;

            if (idx != -1)
                includeProfit += dp[idx];

            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }
};
