class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(mat[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        int drow[] = {1,0,-1,0}; //delta row which will be the neighbour
        int dcol[] = {0,1,0,-1};
        
        int tm = 0;
        
        while(!q.empty()){
            int r = q.front().first.first; //row h
            int c = q.front().first.second; // colm 
            int t = q.front().second; //time hai
            q.pop();
            
            tm = max(tm,t);
            
            for(int i = 0; i<4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i]; //neighbouring row of curr idx
                 
                if(isSafe(nrow, ncol, n, m) && vis[nrow][ncol] != 2 && mat[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(vis[i][j]!=2 && mat[i][j] == 1 ){
                    return -1;
                }
            }
        }
        return tm;
    }
    
    
    private:
      bool isSafe(int r, int c, int n, int m){
          return (r >= 0 && r<n && c >=0 && c<m);
      }
};