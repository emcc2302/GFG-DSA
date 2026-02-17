class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        vector<int> starts, ends;
        
        for (auto& interval : arr) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        
        // Sort both to process events in chronological order
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int n = arr.size();
        int max_overlaps = 0;
        int current_overlaps = 0;
        
        int i = 0, j = 0;
        
        // Sweep through the timeline
        while (i < n) {
            // If the next interval starts before or at the same time 
            // the current oldest interval ends, they overlap.
            if (starts[i] <= ends[j]) {
                current_overlaps++;
                max_overlaps = max(max_overlaps, current_overlaps);
                i++;
            } else {
                // An interval has ended
                current_overlaps--;
                j++;
            }
        }
        
        return max_overlaps;
    }
};