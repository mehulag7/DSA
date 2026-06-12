class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[ind]){
                ind++;
                nums[ind]=nums[i];
            }
        }
        return ind+1;
    }
};