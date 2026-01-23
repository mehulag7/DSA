class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int i=0,j=0;
        int ans=-1;
        unordered_map<char,int> mpp;
        while(j<s.length()){
           mpp[s[j]]++;
           if(mpp.size()>k){
            mpp[s[i]]--;
            if(mpp[s[i]]==0) mpp.erase(s[i]);
            i++;
           }
           if(mpp.size()==k)
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};