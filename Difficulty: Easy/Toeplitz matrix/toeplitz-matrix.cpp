class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int i=0, j=0;
        
        while(i<n){
            int el=mat[i][j];
            int r=i, c=j;
            while(r<n && c<m){
                if(el!=mat[r][c]) return false;
                r++, c++;
            }
            i++;
        }
        
        i=0, j=1;
        
        while(j<m){
            int el=mat[i][j];
            int r=i, c=j;
            while(r<n && c<m){
                if(el!=mat[r][c]) return false;
                r++, c++;
            }
            j++;
        }
        
        return true;
    }
};