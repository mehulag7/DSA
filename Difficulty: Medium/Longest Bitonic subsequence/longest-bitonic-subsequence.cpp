class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
       vector<long long> ans(n,1),ans1(n,1);
       for(int i=1;i<n;i++){
        //int p=ans[i];
        for(int j=i-1;j>=0;j--){
            
            if(nums[j]<nums[i]){
                ans[i]=max(1+ans[j],ans[i]);
            }
        }
       }
       long long p=0;
        for(int i=n-1;i>=0;i--){
        //int p=ans[i];
        for(int j=i+1;j<n;j++){
            
            if(nums[j]<nums[i]){
                ans1[i]=max(1+ans1[j],ans1[i]);
            }
        }
        if(ans[i]!=1 && ans1[i]!=1)
        p=max(p,ans[i]+ans1[i]-1);
       }
       return p;
    }
};
