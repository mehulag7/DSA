class Solution {
public:
    void create(int i,vector<vector<int>> dp,vector<string>& v,string m,string s){
           if(i==0) {
            v.push_back(m);
            return;
           }
           for(int j=0;j<dp[i].size();j++){
            int p=dp[i][j];
            string l=s.substr(dp[i][j],i-dp[i][j]);
            if(m.length()!=0) l+=" "+m;
            create(dp[i][j],dp,v,l,s);
           }
           return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<vector<int>> dp(n + 1);
        dp[0].push_back(0);

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j].size() && st.count(s.substr(j, i - j))){
                    dp[i].push_back(j);
                }
            }
        }
        vector<string> v;
        for(int i=0;i<dp[n].size();i++) cout<<dp[n][i]<<endl;
        string m="";
        create(n,dp,v,m,s);
        return v;
    }
};