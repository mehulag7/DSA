class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=-1;
        int low=0,high=nums.size()-1;
        if(high==0) return nums[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(low==high) {
                ans=nums[low];
                return ans;
            }
            if(mid%2){
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else{
                    if(nums[mid]!=nums[mid+1]) {
                        ans=nums[mid];
                        return ans;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }
            else{
                                if(nums[mid]==nums[mid+1]){
                    low=mid+2;
                }
                else{
                    if(nums[mid]!=nums[mid-1]) {
                        ans=nums[mid];
                        return ans;
                    }
                    else{
                        high=mid-2;
                    }
                }
            }
        }
        return ans;
    }
};