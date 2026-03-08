class Solution {
public:
    int bs(vector<int>& nums,int low,int high,int target){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else{
            return max(bs(nums,mid+1,high,target),bs(nums,low,mid-1,target));
        }
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(bs(nums,0,n-1,target)==-1) return false;
        else return true;
    }
};