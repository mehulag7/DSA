class Solution {
public:
    void tsum(vector<int>& nums, long long target, int k, vector<vector<int>>& ans) {
        int n = nums.size();

        for(int i = k + 1; i < n; i++){
            // ✅ correct duplicate check
            if(i > k + 1 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;
            while(l < r){
                long long sum = (long long)nums[i] + nums[l] + nums[r];

                if(sum == target){
                    ans.push_back({nums[k], nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            tsum(nums, (long long)target - nums[i], i, ans);
        }
        return ans;
    }
};
