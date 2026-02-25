#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        
        if (s1.length() != s2.length())
            return false;
        
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        
        for (int i = 0; i < s1.length(); i++) {
            
            char c1 = s1[i];
            char c2 = s2[i];
            
            if (map1.count(c1)) {
                if (map1[c1] != c2)
                    return false;
            } else {
                map1[c1] = c2;
            }
            
            if (map2.count(c2)) {
                if (map2[c2] != c1)
                    return false;
            } else {
                map2[c2] = c1;
            }
        }
        
        return true;
    }
};