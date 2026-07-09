class Solution {
public:
    vector<int> solve(string needle,int m){
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

        return lps;
    }
    int strStr(string haystack, string needle) {
       int n=haystack.size();
       int m=needle.size();
       vector<int> lps=solve(needle,m);
       int i=0;
       int j=0;
       while(i<n){
        if(haystack[i]==needle[j]){
            i++;
            j++;
        }
        if(j==m){
            return i-j;
        }
        else if(i<n && haystack[i]!=needle[j]){
            if(j==0) i++;
            else{
                j=lps[j-1];
            }
        }
       }
       return -1;
    }
};