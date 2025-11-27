class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int OR = 0;
        for (int x : arr) {
            OR |= x;
        }
        
        int n = arr.size();
        return OR * (1 << (n - 1));
    }
};
