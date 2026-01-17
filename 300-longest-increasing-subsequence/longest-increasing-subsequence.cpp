class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<long long> ans(n,1);
       for(int i=1;i<n;i++){
        int p=ans[i];
        for(int j=i-1;j>=0;j--){
            
            if(nums[j]<nums[i]){
                ans[i]=max(p+ans[j],ans[i]);
            }
        }
       }
       return *max_element(ans.begin(),ans.end());
    }
};