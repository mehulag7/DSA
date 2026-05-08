class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int r=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<intervals[i-r-1][1]){
                intervals[i-r-1][1]=min(intervals[i-r-1][1],intervals[i][1]);
                r++;
                ans++;
            }
            else{
                r=0;
            }
        }
        return ans;
    }
};