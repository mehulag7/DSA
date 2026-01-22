class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int> v(26,0);
         int i=0;
         int ans=0;
         for(int j=0;j<s.size();j++){
            v[s[j]-'A']++;
            int mx=*max_element(v.begin(),v.end());
            int sz=j-i+1;
            if(sz-mx>k){
                v[s[i]-'A']--;
                i++;
            }
            if(sz-mx<=k){
                ans=max(ans,j-i+1);
            }
         }
         return ans;
    }
};