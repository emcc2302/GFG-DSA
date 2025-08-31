class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // width
            int width = right - left;

            // height is min of two
            int height = min(arr[left], arr[right]);

            // calculate area
            int area = width * height;

            maxArea = max(maxArea, area);

            // move the smaller height pointer
            if (arr[left] < arr[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};
