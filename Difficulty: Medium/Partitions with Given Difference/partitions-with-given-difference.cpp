class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
          long long n=arr.size();
	  long long m=1e9+7;
	  vector<vector<long long>> dp(n,vector<long long>(1e3+1,0));
	  dp[0][0]=1;
	  dp[0][arr[0]]+=1;
	  for(int i=1;i<n;i++){
		for(int j=0;j<=1e3;j++){
			long long p=0;
			dp[i][j]=dp[i-1][j];
			if(j-arr[i]>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-arr[i]])%m;
		}
	  }
	  long long ans=0,sum=0;
	  for(int i=0;i<n;i++) sum+=arr[i];
	  long long k=(sum+diff);
	  if(k%2) return 0;
	  else{
	      k=k/2;
	      long long p=sum-diff;
	      if(p<0 || p%2) return 0;
	      else{
	          p=p/2;
	          if(p==k){
	             // dp[n-1][p]/=2;
	          }
	          ans=dp[n-1][p];
	      }
	  }
	  return ans;
    }
};