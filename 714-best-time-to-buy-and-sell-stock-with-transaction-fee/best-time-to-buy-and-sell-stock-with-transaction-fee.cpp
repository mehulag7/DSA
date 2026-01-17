class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
       // return solve(0,1,0,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                       // dp[i][j][1]=dp[i+1][j][0];
                        if(j){
            int p=-prices[i]+dp[i+1][0];
            int d=dp[i+1][1];
             dp[i][j]=max(p,d);
        }
        else{
            int p=prices[i]+dp[i+1][1]-fee;
            int d=dp[i+1][0];
            dp[i][j]=max(p,d);
        }
                }
            }
            return dp[0][1];
    }
};