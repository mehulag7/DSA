class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> v=nums;
        long long n=v.size();
        vector<long long> dp(n,1e6);
        dp[0]=0;
        long long c=0;
        for(int i=0;i<n;i++){
           if(i+v[i]<n){
            if(dp[i+v[i]]==1e6) dp[i+v[i]]=i;
           }
           else {
            if(dp[n-1]==1e6) dp[n-1]=i;
           }
        }
        for(int i=n-2;i>=0;i--){
            if(dp[i]>dp[i+1]) dp[i]=dp[i+1];
        }
        long long count=0;
        c=n-1;
        while(c!=0){
          c=dp[c];
          count++;
        }
        return count;
    }
};