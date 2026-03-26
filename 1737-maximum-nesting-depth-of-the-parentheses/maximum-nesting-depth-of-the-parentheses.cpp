class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int ans=0;
        int l=0;
        for(int i=0;i<s.length();i++){
           if(s[i]=='(') {
            l++;
            ans=max(ans,l);
           }
           else if(s[i]==')') l--;
        }
        return ans;
    }
};