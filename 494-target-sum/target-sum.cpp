class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(abs(target)>sum) return 0;
        vector<vector<long long>> dp(n+1,vector<long long>(2*sum+1,0));
        dp[0][sum-nums[0]]++;
        dp[0][sum+nums[0]]++;
        for(int i=1;i<n;i++){
            for(int j=0;j<=2*sum;j++){
               if(j-nums[i]>=0) dp[i][j]=dp[i-1][j-nums[i]];
               if(j+nums[i]<=2*sum) dp[i][j]+=dp[i-1][j+nums[i]];
            }
        }
        return dp[n-1][target+sum];
    }
};