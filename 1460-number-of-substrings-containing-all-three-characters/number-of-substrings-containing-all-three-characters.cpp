class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,ans=0,t=0;
        int a=0,b=0,c=0;
        while(j<s.length()){
            t+=(j+1);
           if(s[j]=='a') a++;
           if(s[j]=='b') b++;
           if(s[j]=='c') c++;
           while(a>0 && b>0 && c>0){
            if(s[i]=='a') a--;
           if(s[i]=='b') b--;
           if(s[i]=='c') c--;
           i++;
           }
           if(a<1 || b<1 || c<1){
            ans+=j-i+1;
           }
          // cout<<ans<<endl;
           
           j++;
        }
       // cout<<t<<endl;
       return t-ans;
    }
};