class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>, greater<int>>pq;
        
        for(int i=0;i<=k;i++){
            pq.push(arr[i]);
        }
        int index=0;
        for(int i=k+1;i<arr.size();i++){
            arr[index++]=pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};