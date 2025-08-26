class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        int i = 0, j = 0;
        
        // two-pointer approach
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        
        return (i == n); // true if all characters of s1 matched in order
    }
};
