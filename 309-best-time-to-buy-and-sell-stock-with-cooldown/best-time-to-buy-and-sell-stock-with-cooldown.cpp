class Solution {
public:
int solve(int ind,int buy,int cd,vector<int>&prices,vector<vector<vector<long long>>>& dp){
    if(ind==prices.size()) return 0;
    if(dp[ind][buy][cd]!=-1) return dp[ind][buy][cd];
    if(cd){
       return dp[ind][buy][cd]=solve(ind+1,buy,0,prices,dp);
    }
    else{
        if(buy){
            int p=-prices[ind]+solve(ind+1,0,0,prices,dp);
            int d=solve(ind+1,1,0,prices,dp);
            return dp[ind][buy][cd]=max(p,d);
        }
        else{
            int p=prices[ind]+solve(ind+1,1,1,prices,dp);
            int d=solve(ind+1,0,0,prices,dp);
            return dp[ind][buy][cd]=max(p,d);
        }
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<long long>> dp(n+2,vector<long long>(2,0));
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
            int p=prices[i]+dp[i+2][1];
            int d=dp[i+1][0];
            dp[i][j]=max(p,d);
        }
                }
            }
            return dp[0][1];
    }
};