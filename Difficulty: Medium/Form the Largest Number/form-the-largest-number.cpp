class Solution {
  public:
    string findLargest(vector<int> &arr) {
 
        vector<string> nums;
        for (int x : arr) {
            nums.push_back(to_string(x));
        }
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        if (nums[0] == "0") return "0";
        
        string result;
        for (auto &s : nums) {
            result += s;
        }
        return result;
    }
};