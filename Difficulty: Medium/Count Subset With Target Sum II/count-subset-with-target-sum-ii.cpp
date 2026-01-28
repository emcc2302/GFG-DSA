class Solution {
  public:
    void genSums(int idx, int end, vector<int> &arr, long long sum, vector<long long> &sums){
        if(idx == end){
            sums.push_back(sum);
            return;
        }
        // not take
        genSums(idx + 1, end, arr, sum, sums);
        // take
        genSums(idx + 1, end, arr, sum + arr[idx], sums);
    }

    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<long long> leftSums, rightSums;

        genSums(0, mid, arr, 0, leftSums);
        genSums(mid, n, arr, 0, rightSums);

        sort(rightSums.begin(), rightSums.end());

        long long ans = 0;

        for(long long x : leftSums){
            long long need = (long long)k - x;
            auto lb = lower_bound(rightSums.begin(), rightSums.end(), need);
            auto ub = upper_bound(rightSums.begin(), rightSums.end(), need);
            ans += (ub - lb);
        }

        return (int)ans;
    }
};
