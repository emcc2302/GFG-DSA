class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        int minLen = INT_MAX;
        int start = -1;
        
        int i = 0, j = 0;
        
        while (i < n) {
            if (s1[i] == s2[j]) {
                j++;
            }
            
            if (j == m) {
                int end = i;
                
                j--;
                while (j >= 0) {
                    if (s1[i] == s2[j]) {
                        j--;
                    }
                    i--;
                }
                
                i++; 
                j++;
                
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
            
            i++;
        }
        
        if (start == -1) return "";
        return s1.substr(start, minLen);
    }
};
