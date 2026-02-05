class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans=nums[0];
        long long g=0;
        long long s=-1e9;
        long long m=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(ans<0) ans=0;
                m=1;
               if(g!=0) ans=max(ans,g/s);
                g=0;
                s=-1e9;
                continue;
            }
            m=m*nums[i];
            ans=max(ans,m);
            if(m<0){
                if(s==-1e9) s=m;
                else{
                    g=m;
                }
            }
            //cout<<ans<<" "<<m<<" "<<g<<" "<<s<<endl;
        }
           if(g!=0) ans=max(ans,g/s);
        return ans;
    }
};