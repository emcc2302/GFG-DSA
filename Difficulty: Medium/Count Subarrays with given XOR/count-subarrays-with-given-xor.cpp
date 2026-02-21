class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;   // base case
        
        long count = 0;
        int prefixXor = 0;
        
        for (int num : arr) {
            prefixXor ^= num;
            
            int needed = prefixXor ^ k;
            if (mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            
            mp[prefixXor]++;
        }
        
        return count;
    }
};