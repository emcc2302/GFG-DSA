class Solution {
  public:
    vector<int> subsetXOR(int n) {
        int px = 0;
        for(int i = 1; i <= n; i++) px ^= i;
        
        if(px == n){
            vector<int> ans(n);
            for(int i = 1; i <= n; i++) ans[i-1] = i;
            return ans;
        }
        
        int missing = px ^ n;
        
        if(missing >= 1 && missing <= n){
            vector<int> ans;
            for(int i = 1; i <= n; i++){
                if(i != missing) ans.push_back(i);
            }
            return ans;
        }
        
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(n ^ 1);
        return ans;
    }
};

