class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> hint(n, 0); // tracks when flips expire
        int flip = 0, res = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flip ^= hint[i - k]; // remove expired flip effect
            }
            // If current bit after considering flips is 0, we must flip
            if ((arr[i] ^ flip) == 0) {
                if (i + k > n) return -1; // cannot flip
                res++;
                flip ^= 1;        // new flip starts
                hint[i] = 1;      // this flip will expire after k steps
            }
        }
        return res;
    }
};
