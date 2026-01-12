class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,1e9));
         if(amount==0) return 0;
         for(int i=0;i<n;i++) dp[i][0]=0;
         for(int i=1;i<=amount;i++){
           if(i-coins[0]>=0 ){
            if(dp[0][i-coins[0]]!=1e9) dp[0][i]=1+dp[0][i-coins[0]];
           }
         }
         for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i-1][j];
                if(j-coins[i]>=0){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
                }
            }
         }
         if(dp[n-1][amount]==1e9){
            return -1;
         }
         else return dp[n-1][amount];
    }
};