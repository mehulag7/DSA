class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int v=0,s=n-1,l=0,r=m-1;
        vector<int> ans;
        while(v<=s && l<=r){
        for(int i=l;i<=r;i++) ans.push_back(matrix[v][i]);
        v++;
        if(v>s) break;
        for(int j=v;j<=s;j++) ans.push_back(matrix[j][r]);
        r--;
        if(r<l) break;
        for(int i=r;i>=l;i--) ans.push_back(matrix[s][i]);
        s--;
        for(int j=s;j>=v;j--) ans.push_back(matrix[j][l]);
        l++;
        }
        return ans;
    }
};