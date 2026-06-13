class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1]) return nums[0];
        int low=0,high=n-1;
        int mn=nums[n-1];
        while(low<=high){
           int mid=(low+high)/2;
           mn=min(mn,nums[mid]);
           if(nums[mid]>=nums[low]){
            mn=min(mn,nums[low]);
            low=mid+1;
           }
           else{
            high=mid-1;
           }
        }
        return mn;
    }
};