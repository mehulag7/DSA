class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n=v.size();
        int i=0,j=n-2,l=0;
        while(i<=j){
            
            for(int k=i;k<=j;k++){
            long long temp=v[k][n-1-l];
            v[k][n-1-l]=v[l][k];
            long long b=v[n-1-l][n-1-k];
            v[n-1-l][n-1-k]=temp;
            temp=b;
            b=v[n-1-k][l];
            v[n-1-k][l]=temp;
            temp=b;
            v[l][k]=temp;
            }
            i++;
            j--;
            l++;
        }
    }
};