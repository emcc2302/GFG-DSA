#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        int ALL = (1 << n) - 1;
        const int INF = 1e9;
        // dp[mask][i] = minimum cost to start from city 0, visit the set of cities in `mask`, and end at city i.
        vector<vector<int>> dp(1 << n, vector<int>(n, INF));

        // Base: starting from city 0, only city 0 visited
        dp[1][0] = 0;

        for (int mask = 1; mask <= ALL; ++mask) {
            for (int u = 0; u < n; ++u) {
                if (!(mask & (1 << u))) continue;  // u not in mask, skip
                // dp[mask][u] is valid only if u is visited in mask
                for (int v = 0; v < n; ++v) {
                    if (mask & (1 << v)) continue;  // v already visited
                    int nmask = mask | (1 << v);
                    dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + cost[u][v]);
                }
            }
        }

        // Finally, all cities visited — find min cost ending anywhere + return to 0
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            if (i == 0) continue;
            ans = min(ans, dp[ALL][i] + cost[i][0]);
        }
        // Special case: if n == 1, cost is 0
        if (n == 1) ans = 0;
        return ans;
    }
};
