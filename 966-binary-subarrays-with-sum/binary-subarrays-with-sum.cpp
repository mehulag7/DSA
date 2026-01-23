class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<long long,long long> mpp;
        mpp[0]++;
        long long ans=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=mpp[sum-goal];
            mpp[sum]++;
        }
        return ans;
    }
};