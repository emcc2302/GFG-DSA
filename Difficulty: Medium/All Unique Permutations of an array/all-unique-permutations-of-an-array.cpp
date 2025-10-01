class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // important for skipping duplicates
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(n, 0);
        recurPermute(arr, ans, ds, freq, n);
        return ans;
    }

private:
    void recurPermute(vector<int>& arr, vector<vector<int>> &ans,
        vector<int>& ds, vector<int>& freq, int n) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (freq[i] == 0) {
                // skip duplicates: if current == prev and prev not used
                if (i > 0 && arr[i] == arr[i-1] && freq[i-1] == 0) continue;

                ds.push_back(arr[i]);
                freq[i] = 1;
                recurPermute(arr, ans, ds, freq, n);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
};