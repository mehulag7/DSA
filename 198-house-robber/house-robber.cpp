class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        v[0]=nums[0];
       if(n>1) v[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++){
            v[i]=max(v[i-1],v[i-2]+nums[i]);
        }
        return v[n-1];
    }
};