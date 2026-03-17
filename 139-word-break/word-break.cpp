class Solution {
public:
bool check(string s,int i,int j,vector<string>& wordDict,vector<vector<int>>& dp){
string p=s.substr(i,j-i+1);
if(dp[i][j]!=-1) return dp[i][j];
for(auto w:wordDict){
if(w==p) return dp[i][j]=true;
}
bool k=false;
for(int d=i;d<j;d++){
if(check(s,i,d,wordDict,dp)&check(s,d+1,j,wordDict,dp)){
    k=true;
    break;
}
}
return dp[i][j]=k;
}
    bool wordBreak(string s, vector<string>& wordDict) {
     int n=s.length();
     bool ans=false;
     vector<vector<int>> dp(n,vector<int>(n,-1));
     return check(s,0,n-1,wordDict,dp);
    }
};