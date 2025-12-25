class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int curr = mat[i][j];

                // If any existing neighbor violates curr >= neighbor, skip
                if (i > 0  && !(curr >= mat[i-1][j])) continue;   // up
                if (i+1 < n && !(curr >= mat[i+1][j])) continue;  // down
                if (j > 0  && !(curr >= mat[i][j-1])) continue;   // left
                if (j+1 < m && !(curr >= mat[i][j+1])) continue;  // right

                // curr >= all valid neighbors -> peak
                return {i, j};
            }
        }

        return {-1, -1};
    }
};
