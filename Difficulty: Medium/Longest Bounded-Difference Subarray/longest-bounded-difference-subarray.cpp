#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> maxD, minD; // stores indices
        int left = 0, bestLen = 0, start = 0;

        for (int right = 0; right < n; right++) {
            // Maintain max deque
            while (!maxD.empty() && arr[maxD.back()] < arr[right])
                maxD.pop_back();
            maxD.push_back(right);

            // Maintain min deque
            while (!minD.empty() && arr[minD.back()] > arr[right])
                minD.pop_back();
            minD.push_back(right);

            // Shrink window if condition breaks
            while (!maxD.empty() && !minD.empty() &&
                   arr[maxD.front()] - arr[minD.front()] > x) {
                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                left++;
            }

            // Update best window
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                start = left;
            }
        }

        return vector<int>(arr.begin() + start, arr.begin() + start + bestLen);
    }
};
