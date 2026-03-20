class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int k) {
        int i=matrix.size();
        int j=matrix[0].size();
        int low=0,high=i*j-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/j;
            int col=mid-row*j;
            if(matrix[row][col]<k){
                low=mid+1;
            }
            else if(matrix[row][col]>k){
                high=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};