class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int ind=-1;
        string p;
        int k=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
               if(k==0) continue;
               else{
                if(!p.empty())
                p=s.substr(ind,k)+" "+p;
                else p=s.substr(ind,k);
                k=0;
               }
            }
            else{
                if(k==0) ind=i;
                k++;
            }
        }
        if(k!=0){
            if(!p.empty())
                p=s.substr(ind,k)+" "+p;
                else p=s.substr(ind,k);
        }
        return p;
    }
};