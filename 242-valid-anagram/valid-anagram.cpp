class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0),c(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            c[t[i]-'a']++;
        }
        for(int i=0;i<26;i++) if(v[i]!=c[i]) return false;
        return true;
    }
}; 