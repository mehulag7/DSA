class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<n;i++){
                count+=nums[i]/mid;
                if(nums[i]%mid) count++;
            }
            cout<<mid<<" "<<count<<endl;
            if(count<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};