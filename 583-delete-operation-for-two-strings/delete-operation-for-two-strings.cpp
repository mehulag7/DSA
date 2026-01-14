class Solution {
public:
int solve(string &s , string &t , int n , int m , vector<vector<int>>&dp){
        if(n == 0 || m ==0 ){
            return 0 ;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n-1] == t[m-1]){
            return dp[n][m] = 1 + solve(s , t , n-1 , m-1 , dp);
        }
        else{
            return dp[n][m] = max(solve(s, t, n-1 , m ,dp) , solve(s ,t , n ,m-1 ,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int a=word1.length();
        int b=word2.length();
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        return a+b-2*solve(word1,word2,a,b,dp);
    }
};