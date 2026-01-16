class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Build intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int start = max(0, i - arr[i]);
                int end = min(n - 1, i + arr[i]);
                intervals.push_back({start, end});
            }
        }

        // Sort by start time
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int i = 0;
        int coveredTill = 0;

        // Step 2: Greedy covering
        while(coveredTill < n) {
            int farthest = coveredTill;

            while(i < intervals.size() && intervals[i].first <= coveredTill) {
                farthest = max(farthest, intervals[i].second + 1);
                i++;
            }

            // No progress means impossible
            if(farthest == coveredTill)
                return -1;

            ans++;
            coveredTill = farthest;
        }

        return ans;
    }
};
