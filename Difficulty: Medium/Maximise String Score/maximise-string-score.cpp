#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        const int A = 256;
        int n = (int)s.size();
        if (n <= 1) return 0;

        // Build can matrix
        vector<array<bool,256>> can(A);
        for(int i=0;i<A;i++){
            for(int j=0;j<A;j++) can[i][j] = false;
            can[i][i] = true; // same-character jumps allowed
        }
        for(auto &v : jumps){
            if(v.size() >= 2){
                unsigned char a = (unsigned char)v[0];
                unsigned char b = (unsigned char)v[1];
                can[a][b] = true;
            }
        }

        // prefix ascii sums pref[k] = sum s[0..k-1]
        vector<long long> pref(n+1, 0);
        for(int i=0;i<n;i++) pref[i+1] = pref[i] + (unsigned char)s[i];

        const long long NEG = LLONG_MIN / 4;

        // bestPair[src][t] = maximum over indices i with s[i]==src of (DP[i] - pref[i] + cp_weighted(t, i))
        // cp_weighted(t,i) = ascii(t) * count_t_up_to_i (i exclusive)
        static long long bestPair[256][256];
        for(int i=0;i<A;i++) for(int j=0;j<A;j++) bestPair[i][j] = NEG;

        vector<long long> dp(n, NEG);
        dp[0] = 0; // start at index 0 with score 0

        // currentCount[t] = number of occurrences of char t in s[0..i-1]
        vector<int> currentCount(A, 0);

        long long answer = 0;

        for(int i = 0; i < n; ++i){
            if(i > 0){
                unsigned char t = (unsigned char)s[i];
                // baseConst = pref[i] - cp_weighted(t, i)
                long long cpw_i = (long long)currentCount[t] * (unsigned char)t;
                long long baseConst = pref[i] - cpw_i;

                long long bestVal = NEG;
                // try all source chars that can jump to t
                for(int src = 0; src < A; ++src){
                    if(!can[src][t]) continue;
                    if(bestPair[src][t] == NEG) continue;
                    long long cand = bestPair[src][t] + baseConst;
                    if(cand > bestVal) bestVal = cand;
                }
                dp[i] = bestVal;
            } else {
                // dp[0] already set to 0
            }

            if(dp[i] != NEG && dp[i] > answer) answer = dp[i];

            // If dp[i] is reachable, use index i as a predecessor for future indices:
            if(dp[i] != NEG){
                unsigned char src = (unsigned char)s[i];
                // For each target character t, cp_weighted(t,i) = ascii(t) * currentCount[t]
                for(int t = 0; t < A; ++t){
                    long long cpw = (long long)currentCount[t] * (unsigned char)t;
                    long long val = dp[i] - pref[i] + cpw;
                    if(val > bestPair[src][t]) bestPair[src][t] = val;
                }
            }

            // Now include s[i] into counts (so counts are for prefix up to i+1 for next iteration)
            currentCount[(unsigned char)s[i]]++;
        }

        return (int)answer;
    }
};
