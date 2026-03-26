class Solution {
public:
    int myAtoi(string s) {
        long long v=0;
        int p=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' ') {
                p=i+1;
            }
            else break;
        }
        int k=1;
        if(p!=n && s[p]=='-') {
            k=-1;
        }
        if(p!=n && (s[p]=='-' || s[p]=='+')) p++;
        for(int i=p;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                v=v*10+(s[i]-'0');
                if(v*k<INT_MIN) {
                    v=INT_MIN;
                    return v;
                }
                else if(v*k>INT_MAX) {
                    v=INT_MAX;
                    return v;
                }
            }
            else break;
        }
        v*=k;
        return v;
    }
};