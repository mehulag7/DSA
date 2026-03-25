class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        if(n==1) return strs[0];
        for(int j=0;j<strs[0].size();j++){
            int p=1;
        for(int i=1;i<n;i++){
           if(strs[i].size()>j && strs[i][j]==strs[0][j]){
               continue;
           }
           else{
            p=0;
            break;
           }
        }
        if(p==1) ans+=strs[0][j];
        else break;
    }
    return ans;
    }
};