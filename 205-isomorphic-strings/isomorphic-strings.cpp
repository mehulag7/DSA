class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mpp,mpp2;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            if(mpp.count(s[i])==0) mpp[s[i]]=t[i];
            else if(mpp[s[i]]!=t[i]) return false;
        }
        for(int i=0;i<s.length();i++){
            if(mpp2.count(t[i])==0) mpp2[t[i]]=s[i];
            else if(mpp2[t[i]]!=s[i]) return false;
        }
        return true;
    }
};