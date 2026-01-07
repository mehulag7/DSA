class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long t=0;
        long long n=nums.size();
        for(int i=0;i<n;i++) t+=nums[i];
        if(t%2) return false;
        t/=2;
        vector<vector<bool>> dp(n,vector<bool>(t+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
      if(nums[0]<=t)  dp[0][nums[0]]=true;
      for(int i=1;i<n;i++){
        for(int j=1;j<=t;j++){
              dp[i][j]=dp[i-1][j];
              if(j-nums[i]>=0) dp[i][j]=dp[i][j]||dp[i-1][j-nums[i]];
        }
      }
      return dp[n-1][t];
    }
};