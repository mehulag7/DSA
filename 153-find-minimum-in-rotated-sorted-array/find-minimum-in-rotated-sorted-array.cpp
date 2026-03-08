class Solution {
public:
void bs(vector<int>& nums,int low,int high,int &ans){
        if(low>high) return;
        int mid=(low+high)/2;
        if(nums[mid]<ans) {
            ans=nums[mid];

        }
         bs(nums,mid+1,high,ans);
         bs(nums,low,mid-1,ans);
         return;
    }
    int findMin(vector<int>& nums) {
        int ans=nums[0];
        int low=0;
        int high=nums.size()-1;
        bs(nums,low,high,ans);
        return ans;
    }
};