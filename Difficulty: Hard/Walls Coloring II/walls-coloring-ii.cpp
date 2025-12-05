class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;

        int k = costs[0].size();
        if(k == 0) return 0;

        // If only 1 color and more than 1 wall → impossible
        if(k == 1 && n > 1) return -1;
        
        // DP array for previous row
        vector<int> prev(k);

        // Initialize DP for first wall
        for(int c = 0; c < k; c++) prev[c] = costs[0][c];

        for(int i = 1; i < n; i++) {
            // Find min1 and min2 from prev[]
            int min1 = INT_MAX, min2 = INT_MAX;
            int idx1 = -1;

            for(int c = 0; c < k; c++) {
                if(prev[c] < min1) {
                    min2 = min1;
                    min1 = prev[c];
                    idx1 = c;
                } else if(prev[c] < min2) {
                    min2 = prev[c];
                }
            }

            vector<int> curr(k);

            // Compute DP for current row
            for(int c = 0; c < k; c++) {
                if(c == idx1)
                    curr[c] = costs[i][c] + min2;
                else
                    curr[c] = costs[i][c] + min1;
            }

            prev = curr;
        }

        // Minimum among last row
        int ans = INT_MAX;
        for(int c = 0; c < k; c++) ans = min(ans, prev[c]);

        return ans;
    }
};
