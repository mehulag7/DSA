class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        vector<vector<int>> p(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++){
            p[i+1]=p[i];
            p[i+1][s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int m=1e9,mx=-1;
                for(int k=0;k<26;k++){
                    int l=p[j][k]-p[i][k];
                    if(l>0){
                        m=min(m,l);
                        mx=max(mx,l);
                    }
                }
                ans+=mx-m;
            }
           // cout<<ans<<endl;
        }
        return ans;
    }
};