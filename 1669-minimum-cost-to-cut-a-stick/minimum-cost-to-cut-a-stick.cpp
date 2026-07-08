class Solution {
public:
    int solve(int st,int end,vector<int>& cuts,vector<vector<long long>> &dp){
        if(st>end) return 0;
      if(dp[st][end]!=-1) return dp[st][end];
      if(st==end) return dp[st][end]=cuts[end+1]-cuts[end-1];
      long long ans=1e9;
      for(int i=st;i<=end;i++){
       long long p=cuts[end+1]-cuts[st-1];
       p+=solve(st,i-1,cuts,dp);
       p+=solve(i+1,end,cuts,dp);
       if(p<ans) ans=p;
      }
      return dp[st][end]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int p=cuts.size();
        vector<vector<long long>> dp(p+1,vector<long long>(p+1,-1));
        int ans=solve(1,p-2,cuts,dp);
        for(int i=0;i<=p;i++){
            for(int j=0;j<=p;j++) cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return ans;
    }
};