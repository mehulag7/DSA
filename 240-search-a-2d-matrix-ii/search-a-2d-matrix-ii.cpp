class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col=-1;
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[0][mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        col=high;
        low=0,high=n-1;
        for(int i=0;i<=col;i++){
            while(low<=high){
                int mid=(low+high)/2;
                if(matrix[mid][i]==target){
                    return true;
                }
                else if(matrix[mid][i]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            low=0;
        }
        return false;
    }
};