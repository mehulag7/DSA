class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int> v(32,0);
        int ans=0;
        for(int i=0;i<=31;i++){
            if(start&(1<<i)) v[i]++;
            if(goal&(1<<i)) v[i]--;
            if(v[i]!=0) ans++;
        }
        return ans;
    }
};