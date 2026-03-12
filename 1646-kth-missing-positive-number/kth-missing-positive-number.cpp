class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]-1-mid>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return k+1+high;
    }
};