class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=1e9;
        int low=1,high=1e9;
        int n=piles.size();
        while(low<=high){
            int mid=(high+low)/2;
            long long count=0;
            for(int i=0;i<n;i++){
                count+=piles[i]/mid;
                if(piles[i]%mid) count++; 
            }
            if(count<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};