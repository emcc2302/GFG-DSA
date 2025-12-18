class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> odd, even;

        // Separate odd and even numbers
        for(int x : arr) {
            if(x % 2 != 0) odd.push_back(x);
            else even.push_back(x);
        }

        // Sort odd in descending order
        sort(odd.begin(), odd.end(), greater<int>());

        // Sort even in ascending order
        sort(even.begin(), even.end());

        // Merge back into arr
        int k = 0;
        for(int x : odd) arr[k++] = x;
        for(int x : even) arr[k++] = x;
    }
};
