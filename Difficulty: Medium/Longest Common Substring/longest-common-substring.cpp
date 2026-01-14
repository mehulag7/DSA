class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        long long ans=0;
        long long a=s1.length();
        long long b=s2.length();
       vector<vector<long long>> v(a+1,vector<long long>(b+1,0));
       for(int i=1;i<=a;i++){
           for(int j=1;j<=b;j++){
               if(s1[i-1]==s2[j-1]){
                   v[i][j]=1+v[i-1][j-1];
                   ans=max(ans,v[i][j]);
               }
           }
       }
       return ans;
       
    }
};