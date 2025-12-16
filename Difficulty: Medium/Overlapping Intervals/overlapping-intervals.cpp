class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // If no intervals, just return empty
        if(arr.empty()) return {};

        // Sort intervals by their start times
        sort(arr.begin(), arr.end());

        // Result vector to store merged intervals
        vector<vector<int>> merged;
        merged.push_back(arr[0]);

        // Traverse through all intervals
        for(int i = 1; i < arr.size(); i++) {
            // If current interval overlaps with the last one in merged
            if(merged.back()[1] >= arr[i][0]) {
                // Update the end of the last merged interval
                merged.back()[1] = max(merged.back()[1], arr[i][1]);
            } else {
                // No overlap, push as a new interval
                merged.push_back(arr[i]);
            }
        }

        return merged;
    }
};
