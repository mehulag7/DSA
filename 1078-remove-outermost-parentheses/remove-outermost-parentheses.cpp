class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        vector<int> v;
        v.push_back(0);
        int a=1;
        for(int i=1;i<n;i++){
           if(s[i]=='(') a++;
           else a--;
           if(a==0){
            v.push_back(i);
            v.push_back(i+1);
            i++;
            a++;
           }
        }
        string p="";
        int j=0;
        for(int i=0;i<n;i++){
            if(i==v[j]){
                j++;
                continue;
            }
            p+=s[i];
        }
        return p;
    }
};