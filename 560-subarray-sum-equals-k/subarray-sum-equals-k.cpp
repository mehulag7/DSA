class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum=0;
        map<long long,long long> mpp;
        mpp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans+=mpp[sum-k];
            mpp[sum]++;
        }
        return ans;
    }
};