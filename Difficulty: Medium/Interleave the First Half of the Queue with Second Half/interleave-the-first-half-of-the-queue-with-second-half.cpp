class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
       vector<int> arr;
       while(!q.empty()){
           arr.push_back(q.front());
           q.pop();
       }
       int n = arr.size();
       for(int i = 0 ; i< n/2; i++){
           q.push(arr[i]);
           q.push(arr[i+n/2]);
       }

    }
};