class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool f=false;
        int ind=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                ind=i-1;
                break;
            }
        }
        if(ind==-1){
           reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    int temp=nums[ind];
                    nums[ind]=nums[i];
                    nums[i]=temp;
                    sort(nums.begin()+ind+1,nums.end());
                    break;
                }
            }
        }
    }
};