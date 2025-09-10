class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) last[s[i] - '0'] = i; // last index of each digit

        for (int i = 0; i < n; ++i) {
            int cur = s[i] - '0';
            // try to find a bigger digit (9 down to cur+1) that appears to the right
            for (int d = 9; d > cur; --d) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s; // at most one swap
                }
            }
        }
        return s;
    }
};
