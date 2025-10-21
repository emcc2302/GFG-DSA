class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;

        // Custom comparator for max-heap
        auto cmp = [&](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first < b.first; // larger number first if same freq
            return a.second < b.second; // higher freq first
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        // Push all (num, freq) pairs into heap
        for (auto &p : freq)
            pq.push(p);

        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
