class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        for(int i=0;i<s.length();i++){
            string p=s.substr(i,s.length()-i)+s.substr(0,i);
            if(p==goal) return true;
        }
        return false;
    }
};