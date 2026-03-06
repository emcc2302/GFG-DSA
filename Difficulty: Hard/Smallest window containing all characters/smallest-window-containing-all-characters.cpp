class Solution {
  public:
    string minWindow(string &s, string &p) {
        
        int n = s.size();
        if(p.size() > n) return "";
        
        unordered_map<char,int> mp;
        
        for(char c : p) mp[c]++;
        
        int left = 0, right = 0;
        int required = p.size();  
        
        int minLen = INT_MAX;
        int startIndex = 0;
        
        while(right < n) {
            
            if(mp[s[right]] > 0)
                required--;
            
            mp[s[right]]--;
            right++;
            while(required == 0) {
                
                if(right - left < minLen) {
                    minLen = right - left;
                    startIndex = left;
                }
                
                mp[s[left]]++;
                
                if(mp[s[left]] > 0)
                    required++;
                
                left++;
            }
        }
        
        if(minLen == INT_MAX) return "";
        return s.substr(startIndex, minLen);
    }
};