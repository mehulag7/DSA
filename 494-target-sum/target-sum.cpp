class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2001,0));
        dp[0][1000+nums[0]]=1;
        dp[0][1000-nums[0]]+=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=2000;j++){
                if(j-nums[i]>=0){
                    dp[i][j]+=dp[i-1][j-nums[i]];
                }
                if(j+nums[i]<=2000){
                      dp[i][j]+=dp[i-1][j+nums[i]];
                }
            }
        }
        return dp[n-1][target+1000];
    }
};