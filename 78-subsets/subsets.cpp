class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int p=(1<<n)-1;
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i=p;i>0;i=(i-1)&p){
            vector<int> v;
           for(int j=0;j<nums.size();j++){
              if(i&(1<<j)) v.push_back(nums[j]);
           }
           ans.push_back(v);
        }
        return ans;
    }
};