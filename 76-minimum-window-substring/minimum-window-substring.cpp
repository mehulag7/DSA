class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mpp;
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        int i=0,j=0,count=mpp.size();
        int start=0, ans=1e9;
        int f=t.size();
        while(j<s.size()){
            if(mpp[s[j]]>0) f--;
             mpp[s[j]]--;
            while(f==0){
                if(j-i+1<ans) {
                    start=i;
                    ans=j-i+1;
                }
                    mpp[s[i]]++;
                    if(mpp[s[i]]>0) f++;
                i++;
            }
            j++; 
        }
        if(ans==1e9) return "";
        else return s.substr(start,ans);
    }
};