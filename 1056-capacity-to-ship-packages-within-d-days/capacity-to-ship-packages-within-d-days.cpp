class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=1e9;
       // int ans=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            int count=1;
            int sum=0;
            for(int i=0;i<weights.size();i++){
                if(sum+weights[i]<=mid){
                    sum+=weights[i];
                }
                else{
                    count++;
                    sum=weights[i];
                }
            }
            if(count<=days){
               // ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};