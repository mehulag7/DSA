class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int> ans(n,1);
        int sum=0;
        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(rating[i]<rating[i-1]) {
                ans[i-1]=max(ans[i-1],1+ans[i]);
            }
            sum+=ans[i];
        }
        sum+=ans[0];
        return sum;
    }

};