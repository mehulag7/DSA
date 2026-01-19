class Solution {
public:
long long solve(int i,int j,int k,vector<int> arr,vector<int>&dp){
if(i>j) return 0;
if(i==j) return arr[i];
if(dp[i]!=-1) return dp[i];
long long ans=0;
int mx=arr[i];
for(int f=i;f<=min(j,i+k-1);f++){
    mx=max(mx,arr[f]);
long long p=(f-i+1)*mx+solve(f+1,j,k,arr,dp);
ans=max(ans,p);
}
return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
       //return solve(0,n-1,k,arr,dp);
         for(int i=n-1;i>=0;i--){
            long long ans=0;
int mx=arr[i];
for(int f=i;f<=min(n-1,i+k-1);f++){
    mx=max(mx,arr[f]);
long long p=(f-i+1)*mx+dp[f+1];
ans=max(ans,p);
}
 dp[i]=ans;
         }
         return dp[0];
    }
};