class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
            int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            maxCount = max(maxCount, right[i] - left[i] - 1);
        }

        return maxCount;
    }
};