class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>> 
        > pq;
        
        pq.push({0, {0, 0}});
        effort[0][0] = 0;
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int currEffort = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            if (x == n-1 && y == m-1) {
                return currEffort;
            }
            
            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newEff = max(currEffort, abs(mat[x][y] - mat[nx][ny]));
                    
                    if (newEff < effort[nx][ny]) {
                        effort[nx][ny] = newEff;
                        pq.push({newEff, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};
