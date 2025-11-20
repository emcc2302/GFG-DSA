class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {

        const int INF = 1e9;
        int dist[26][26];

        // Initialize distances
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
        }

        // Fill given transformation costs
        for (int i = 0; i < transform.size(); i++) {
            int x = transform[i][0] - 'a';
            int y = transform[i][1] - 'a';
            dist[x][y] = min(dist[x][y], cost[i]);
        }

        // Floyd–Warshall for all-pairs minimum cost
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            int best = INF;

            // Try making both characters equal to some k
            for (int k = 0; k < 26; k++) {
                if (dist[a][k] < INF && dist[b][k] < INF) {
                    best = min(best, dist[a][k] + dist[b][k]);
                }
            }

            if (best == INF) return -1;  // Not possible
            ans += best;
        }

        return ans;
    }
};
