class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
         vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1] 
                           + pref[i - 1][j] 
                           + pref[i][j - 1] 
                           - pref[i - 1][j - 1];
            }
        }
        int maxSize = min(n, m) ;
        int ans = 0;
        for(int size = 1; size<=maxSize; size++){
            for(int i = 0; i<=n-size; i++){
                 for (int j = 0; j <= m - size; j++) {

                    int r1 = i, c1 = j;
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
    
                    long long sum = pref[r2 + 1][c2 + 1]
                                    - pref[r1][c2 + 1]
                                    - pref[r2 + 1][c1]
                                    + pref[r1][c1];
    
                    if (sum == x) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
