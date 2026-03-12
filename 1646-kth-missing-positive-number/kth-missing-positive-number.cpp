class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p=arr[0]-1;
        if(k<=p){
            return k;
        }
        int n=arr.size();
        if(arr[n-1]<n+k){
            return k+n;
        }
        int ans;
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
        ans=k+1+high;
        return ans;
    }
};