class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<int,int> mp;
        int ans = 0;
        int j = 0;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
            while(mp.size()>k){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    mp.erase(s[j]);
                }
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return mp.size()<k? -1 : ans;
    }
};