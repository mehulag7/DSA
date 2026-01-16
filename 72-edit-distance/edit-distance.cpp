class Solution {
public:
    int solve(string r,string s,int n,int m,vector<vector<int>>&dp){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=1e9) return dp[n][m];
        else{
            int ans=min(solve(r,s,n-1,m,dp),solve(r,s,n,m-1,dp))+1;
            if(r[n-1]==s[m-1]){
                ans=min(ans,solve(r,s,n-1,m-1,dp));
            }
            else {
                ans=min(ans,solve(r,s,n-1,m-1,dp)+1);
            }
            return dp[n][m]=ans;
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                if(word1[i-1]==word2[j-1]){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
            else {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            }
            }
        }
        return dp[n][m];
    }
};