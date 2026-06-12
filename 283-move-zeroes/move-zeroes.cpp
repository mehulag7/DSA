class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int p=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                p++;
                swap(nums[p],nums[i]);
            }
        }
        return;
    }
};