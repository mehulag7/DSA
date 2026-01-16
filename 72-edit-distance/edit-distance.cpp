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
        vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
        return solve(word1,word2,n,m,dp);
    }
};