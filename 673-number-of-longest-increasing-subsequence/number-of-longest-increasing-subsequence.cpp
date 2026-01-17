class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<long long> ans(n,1);
       vector<long long> k(n,1);
       long long maxi=0;
       for(int i=1;i<n;i++){
        //int p=ans[i];
        for(int j=i-1;j>=0;j--){
            
            if(nums[j]<nums[i]){
                if(1+ans[j]>ans[i]){
                   ans[i]=1+ans[j];
                   k[i]=k[j];
                }
                else if(1+ans[j]==ans[i]){
                    k[i]+=k[j];
                }
                else continue;
            }
        }
        maxi=max(maxi,ans[i]);
       }
       int p=0;
       //cout<<maxi<<endl;
       for(int i=0;i<n;i++){
        if(maxi==ans[i]) p+=k[i];
        //cout<<k[i]<<" "<<ans[i]<<endl;
       }
       return max(p,1);
    }
};