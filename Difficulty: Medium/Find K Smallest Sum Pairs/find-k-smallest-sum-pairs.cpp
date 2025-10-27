#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> result;
        int n = arr1.size(), m = arr2.size();
        
        // Min heap: {sum, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Initialize heap with first element of arr2 for each arr1[i]
        for (int i = 0; i < n && i < k; i++) {
            minHeap.push({arr1[i] + arr2[0], i, 0});
        }
        
        // Extract k pairs with smallest sums
        while (k-- > 0 && !minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int i = curr[1], j = curr[2];
            result.push_back({arr1[i], arr2[j]});
            
            // Push next pair in row (i, j+1)
            if (j + 1 < m) {
                minHeap.push({arr1[i] + arr2[j + 1], i, j + 1});
            }
        }
        
        return result;
    }
};
