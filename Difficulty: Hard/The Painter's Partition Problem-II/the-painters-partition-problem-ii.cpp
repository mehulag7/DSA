class Solution {
  public:
    int minTime(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int count=1;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+nums[i]<=mid){
                    sum+=nums[i];
                }
                else{
                    sum=nums[i];
                    count++;
                }
            }
            if(count<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};