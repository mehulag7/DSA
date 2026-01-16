class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int p=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>p){
                ans+=prices[i]-p;
                p=prices[i];
            }
            p=min(p,prices[i]);
        }
        return ans;
    }
};