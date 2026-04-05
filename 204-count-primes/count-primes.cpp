class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<int> p(n+1,1);
        p[0]=0;
        p[1]=0;
        for(int i=2;i*i<=n;i++){
            if(p[i]){
                for(int j=i*i;j<=n;j+=i) p[j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            p[i]+=p[i-1];
        }
        return p[n-1];
    }
};