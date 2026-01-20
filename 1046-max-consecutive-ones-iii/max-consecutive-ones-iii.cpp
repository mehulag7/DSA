class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        vector<int> z;
        z.push_back(0);
        for(int i=0;i<nums.size();i++){
             if(nums[i]==0){
                z.push_back(i+1);
             }
        }
        z.push_back(nums.size()+1);
        if(z.size()-2<=k) return nums.size();
        else{
            int i=1,j=k;
            while(j<=z.size()-2){
                ans=max(ans,z[j+1]-z[i-1]-1);
                j++;
                i++;
            }
            return ans;
        }
    }
};