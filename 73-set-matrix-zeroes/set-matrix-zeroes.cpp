class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
       int m=matrix[0].size();
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(r[i]!=m || c[j]!=n ){
                     matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<r[i]<<" ";
        }
         for(int i=0;i<m;i++){
            cout<<c[i]<<" ";
        }
    }
};