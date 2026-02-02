class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>(1,1));
        if(numRows==1) return ans;
        for(int i=1;i<numRows;i++){
            ans.push_back(vector<int> (ans[i-1].size()+1));
            ans[i][0]=1;
            ans[i][ans[i-1].size()]=1;
            for(int j=1;j<ans[i-1].size();j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
            
        }
        return ans;
    }
};