class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=1,j=0,count=0;
        long long ans=0;
        vector<long long> v;
        v.push_back(0);
        while(j<nums.size()){
            if(nums[j]%2) v.push_back(j+1);
            j++;
            }
            v.push_back(nums.size()+1);
            j=k;
            while(j<v.size()-1){
                ans+=(v[i]-v[i-1])*(v[j+1]-v[j]);
                j++;
                i++;
            }
            return ans;
    }
};