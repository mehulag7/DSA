class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        if(numRows==1) return ans;
        for(int i=1;i<numRows;i++){
            vector<int> g(ans[i-1].size()+1);
            g[0]=1;
            g[ans[i-1].size()]=1;
            for(int j=1;j<ans[i-1].size();j++){
                g[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(g);
        }
        return ans;
    }
};