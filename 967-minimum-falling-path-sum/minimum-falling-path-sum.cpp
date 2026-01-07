class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<long long> prev(n,0),curr(n,0);
        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                long long p=1e9,q=1e9,r=1e9;
                if(j>0) p=prev[j-1];
                q=prev[j];
                if(j<n-1) r=prev[j+1];
                curr[j]=min(p,min(q,r))+matrix[i][j];
            }
            prev=curr;
        }
        long long ans=1e9;
        for(int i=0;i<n;i++) ans=min(ans,prev[i]);
        return ans;
    }
};