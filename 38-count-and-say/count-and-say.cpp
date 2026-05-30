class Solution {
public:
    string solve(string s){
       int count=1;
       char c=s[0];
       string ans="";
       for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            count++;
        }
        else{
            ans+=to_string(count);
            ans+=c;
            c=s[i];
            count=1;
        }
       }
        ans+=to_string(count);
        ans+=c;
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string k="1";
        for(int i=0;i<n-1;i++){
            k=solve(k);
        }
        return k;
    }
};