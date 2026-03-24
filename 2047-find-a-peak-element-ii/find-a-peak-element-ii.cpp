class Solution {
public:
    int maxele(vector<vector<int>>& mat,int n,int m,int mid){
        int ind=-1,val=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>val){
                ind=i;
                val=mat[i][mid];
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=maxele(mat,n,m,mid);
            int left=(mid>0)? mat[row][mid-1]:-1;
            int right=(mid<m-1)? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<right){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};