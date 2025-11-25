class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        // If n is odd, only even index elements contribute
        if (n % 2 == 1) {
            for (int i = 0; i < n; i += 2) {
                res ^= arr[i];
            }
        }
        // If n is even, result remains 0
        return res;
    }
};
