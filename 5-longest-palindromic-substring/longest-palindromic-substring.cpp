class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxlen = 1;

        for(int i=0;i<n;i++){

            // odd length
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxlen){
                    start = l;
                    maxlen = r-l+1;
                }
                l--; r++;
            }

            // even length
            l=i; r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > maxlen){
                    start = l;
                    maxlen = r-l+1;
                }
                l--; r++;
            }
        }

        return s.substr(start,maxlen);
    }
};