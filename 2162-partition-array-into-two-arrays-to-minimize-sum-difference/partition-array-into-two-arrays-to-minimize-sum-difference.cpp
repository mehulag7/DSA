class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        n=n/2;
        long long sum=0;
        vector<long long> v(n),p(n);
        for(int i=0;i<n;i++){
            v[i]=nums[i];
            p[i]=nums[n+i];
            sum+=v[i]+p[i];
        }
        vector<vector<long long>> dp1(n+1),dp2(n+1);
        for(int i=1;i<(1<<n);i++){
           long long l=0;
           long long k=0,s=0;
           for(int j=0;j<n;j++){
            if(i&(1<<j)){
                l++;
                k+=v[j];
                s+=p[j];
            }
           }
           dp1[l].push_back(k);
           dp2[l].push_back(s);
        }
        long long ans=1e9;
        for(int i=1;i<n;i++){
            sort(dp2[i].begin(),dp2[i].end());
        }
        ans=min(ans,min(abs(sum-2*dp1[n][0]),abs(sum-2*dp2[n][0])));
        for(int i=1;i<n;i++){
           for(int j=0;j<dp1[i].size();j++){
            long long h=(sum-2*dp1[i][j])/2;
            long long b=lower_bound(dp2[n-i].begin(),dp2[n-i].end(),h)-dp2[n-i].begin();
            if(b!=dp2[n-i].size()){
                ans=min(ans,abs(sum-2*(dp1[i][j]+dp2[n-i][b])));
            }
            if(b!=0){
                b--;
                ans=min(ans,abs(sum-2*(dp1[i][j]+dp2[n-i][b])));
            }
           }
        }
        return ans;
    }
};