class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int f=0;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>newInterval[1]) {
                ans.push_back(newInterval);
                for(int j=i;j<n;j++) ans.push_back(intervals[j]);
                f=1;
                break;
            }
            else if(intervals[i][0]>=newInterval[0]) {
                ans.push_back({newInterval[0],max(intervals[i][1],newInterval[1])});
                for(int j=i+1;j<n;j++){
                    if(ans[ans.size()-1][1]>=intervals[j][0]){
                        ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[j][1]);
                    }
                    else{
                        ans.push_back(intervals[j]);
                    }
                }
                f=1;
                break;
            }
            else if(intervals[i][0]<newInterval[0] && intervals[i][1]>=newInterval[0]){
                ans.push_back({intervals[i][0],max(newInterval[1],intervals[i][1])});
                for(int j=i+1;j<n;j++){
                    if(ans[ans.size()-1][1]>=intervals[j][0]){
                        ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[j][1]);
                    }
                    else{
                        ans.push_back(intervals[j]);
                    }
                }
                f=1;
                break;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        if(f==0) ans.push_back(newInterval);
        return ans;
    }
};