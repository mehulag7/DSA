class Solution {
  public:
    int lcs(string &t, string &s) {
        // code here
         vector<long long> v(26,-1);
        int a=t.length();
        int b=s.length();
        vector<vector<long long>> dp(a,vector<long long>(b,0));
       
        for(int i=0;i<b;i++){
              if(t[0]==s[i]){
            dp[0][i]=1;
        }
        if(i>0){
            dp[0][i]=max(dp[0][i-1],dp[0][i]);
        }
        }
        for(int i=0;i<a;i++){
              if(t[i]==s[0]){
            dp[i][0]=1;
        }
        if(i>0){
            dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }
        }
        for(int i=1;i<a;i++){
            for(int j=1;j<b;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(t[i]==s[j]){
                    dp[i][j]=max(1+dp[i-1][j-1],dp[i][j]);
                }
            }
        }
        return dp[a-1][b-1];
    }
};
