class Solution {
  public:
    int count(vector<vector<int>> &mat,int mid,int n,int m){
        int count=0;
        for(int i=0;i<n;i++){
            int j=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            count+=j;
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int low=mat[0][0],high=mat[0][m-1];
        for(int i=1;i<n;i++){
            if(mat[i][0]<low) low=mat[i][0];
            if(mat[i][m-1]>high) high=mat[i][m-1];
        }
        int p=n*m/2;
        while(low<=high){
            int mid=(low+high)/2;
            int c=count(mat,mid,n,m);
            if(c>p){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};
