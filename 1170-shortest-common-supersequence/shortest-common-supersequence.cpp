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
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int a=solve(str1,str2,n,m,dp);
        int b=a;
        string s="";
        for(int i=0;i<a;i++) s+="!";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                a--;
                s[a]=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        string x="";
        for(int i=0;i<n+m-b;i++){
           x+="!";
        }
        i=0,j=0;
        int c=0;
        int p=0;
        while(i<n && j<m && c<b){
            if(s[c]==str1[i] && s[c]==str2[j]){
                x[p]=s[c];
                p++;
                i++;
                j++;
                c++;
            }
            else if(s[c]==str1[i]){
               x[p]=str2[j];
               p++;
               j++;
            }
            else if(s[c]==str2[j]){
               x[p]=str1[i];
               p++;
               i++;
            }
            else{
                x[p]=str1[i];
                p++;
                i++;
                x[p]=str2[j];
                p++;
                j++;
            }
        }
        for(;i<n;i++){
            x[p]=str1[i];
            p++;
        }
        for(;j<m;j++){
            x[p]=str2[j];
            p++;
        }
        return x;
    }
};