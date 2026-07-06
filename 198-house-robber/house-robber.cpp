class Solution {
public:
    int rob(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size()+1,{0,0});
        dp[1].first=nums[0];
        for(int i=1;i<nums.size();i++){
           dp[i+1].first=max(dp[i+1].first,dp[i].second+nums[i]);
           dp[i+1].second=max(dp[i].second,dp[i].first);
        }
        return max(dp[nums.size()].first,dp[nums.size()].second);

    }
};