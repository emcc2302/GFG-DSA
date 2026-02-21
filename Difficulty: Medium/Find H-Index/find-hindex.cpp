class Solution {
  public:
    int hIndex(vector<int>& c) {
        // code here
        sort(c.begin(),c.end(), [](const int &a, const int &b) {
            return a > b;
        });
        if(c[0]==0) return 0;
        int ans = 0;
        for(int i = 0; i<c.size(); i++){
            if(c[i]>i) ans = i+1;
        }
        return ans;
    }
};