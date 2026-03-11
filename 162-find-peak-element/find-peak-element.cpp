class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=-1;
        int low=0,high=nums.size()-1;
        if(high==0) return 0;
        while(low<=high){
            int mid=(low+high)/2;
            if((mid==0 ||nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1])) {
                ans=mid;
                return ans;
            }
              if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};