class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ind=0;
        int ans=0;
        map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]==0){
                mpp[s[i]]=i+1;
            }
            else{
                ind=max(mpp[s[i]],ind);
                mpp[s[i]]=i+1;
            }
            ans=max(ans,i+1-ind);
        }
        return ans;
    }
};