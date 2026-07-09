class Solution {
public:
    string longestPrefix(string needle) {
        int m=needle.length();
         vector<int> lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(needle[len]==needle[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        string ans="";
        int c=lps[m-1];
        ans=needle.substr(0,c);
        return ans;
    }
};