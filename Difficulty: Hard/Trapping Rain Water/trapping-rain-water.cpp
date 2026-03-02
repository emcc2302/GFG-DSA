class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        stack<int>st;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                int pop_height=arr[st.top()];
                st.pop();
                
                if(st.empty()) break;
                
                int dis=i-st.top()-1;
                
                int wt=min(arr[st.top()],arr[i])-pop_height;
                
                ans+=dis*wt;
            }
            st.push(i);
        }
        return ans;
    }
};