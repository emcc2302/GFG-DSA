class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>freq;
        int l=0,ans=0;
        
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
            
            while(freq.size()>2){
                freq[arr[l]]--;
                if(freq[arr[l]]==0){
                    freq.erase(arr[l]);
                }
                l++;
            }
            ans=max(ans, i-l+1);
        }
        return ans;
    }
};