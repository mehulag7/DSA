class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        v[0].first=nums[0];
        v[0].second=0;
        if(n>1){
            v[1].first=max(nums[0],nums[1]);
            v[1].second=nums[1];
        }
        for(int i=2;i<n-1;i++){
            v[i].first=max(v[i-2].first+nums[i],v[i-1].first);
            v[i].second=max(v[i-2].second+nums[i],v[i-1].second);
        }
        if(n>2) v[n-1].first=max(v[n-2].first,v[n-3].second+nums[n-1]);
        return v[n-1].first;
    }
};