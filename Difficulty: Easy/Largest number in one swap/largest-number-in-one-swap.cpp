class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        
        int maxIdx = n - 1;
        int left = -1, right = -1;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] > s[maxIdx]) {
                maxIdx = i;
            }
            else if(s[i] < s[maxIdx]) {
                left = i;
                right = maxIdx;
            }
        }

        if(left != -1) {
            swap(s[left], s[right]);
        }

        return s;
    }
};