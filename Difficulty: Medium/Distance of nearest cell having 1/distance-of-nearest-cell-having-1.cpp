class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Push all cells with 1 into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // 4 possible directions
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // Step 2: BFS traversal
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                // Check boundaries and if not visited
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    }
};
