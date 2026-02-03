class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        map<int,int> mpp;
        long long sum=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mpp[sum]!=0) ans=max(ans,i+1-mpp[sum]);
            if(sum==0) ans=max(ans,i+1);
            if(mpp[sum]==0){
                mpp[sum]=i+1;
            }
        }
        return ans;
    }
};
