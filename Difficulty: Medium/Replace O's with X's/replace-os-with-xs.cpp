class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O')
            return;

        // Mark this 'O' as visited (not to be flipped)
        grid[i][j] = '#';

        // Explore in all 4 directions
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    void fill(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Step 1: Mark border-connected 'O's
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') dfs(i, 0, grid);
            if (grid[i][m - 1] == 'O') dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') dfs(0, j, grid);
            if (grid[n - 1][j] == 'O') dfs(n - 1, j, grid);
        }

        // Step 2: Replace surrounded O’s and restore marked ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O')
                    grid[i][j] = 'X';  // Surrounded region
                else if (grid[i][j] == '#')
                    grid[i][j] = 'O';  // Restore non-surrounded
            }
        }
    }
};
