class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==-1) {
            double s=1/x;
            return s;
        }
        if(n==1) return x;
        if(n>0){
        if(n%2){
            double p= myPow(x,n/2);
            return p*p*x;
        }
        else{
            double p= myPow(x,n/2);
            return p*p;
        }
        }
        else{
        if(n%2 ){
            double p= myPow(x,n/2);
            return p*p/x;
        }
        else{
            double p= myPow(x,n/2);
            return p*p;
        }
        }
    }
};