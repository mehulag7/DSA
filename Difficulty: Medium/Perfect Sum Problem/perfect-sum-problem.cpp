class Solution {
  public:
    int perfectSum(vector<int>& arr, int k) {
        // code here
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
	  return dp[n-1][k];
    }
};