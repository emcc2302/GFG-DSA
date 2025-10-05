class Solution {
  void solve(int x, int y, vector<vector<int>>& maze, int n,
             vector<vector<int>>& vis, string path, vector<string>& ans) {
    if (x == n - 1 && y == n - 1) {
      ans.push_back(path);
      return;
    }

    // Direction arrays: D, L, R, U
    string dir = "DLRU";
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && 
          !vis[nx][ny] && maze[nx][ny] == 1) {
        vis[x][y] = 1;
        solve(nx, ny, maze, n, vis, path + dir[i], ans);
        vis[x][y] = 0;
      }
    }
  }

public:
  vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> ans;
    if (maze[0][0] == 0) return ans;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    solve(0, 0, maze, n, vis, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
  }
};
