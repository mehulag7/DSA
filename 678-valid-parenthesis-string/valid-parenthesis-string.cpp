class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else{
                    if(!star.empty()) star.pop();
                    else return false;
                }
            }
            else star.push(i);
        }
        while(!open.empty() && !star.empty()){
            if(open.top()<star.top()){
                open.pop();
                star.pop();
            }
            else return false;
        }
        if(!open.empty()) return false;
        return true;
    }

};