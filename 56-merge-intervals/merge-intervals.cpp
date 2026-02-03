class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
        int k=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ans[k-1][1]){
                ans[k-1][1]=max(intervals[i][1],ans[k-1][1]);
            }
            else {
                ans.push_back(intervals[i]);
                k++;
            }
        }
        return ans;
    }
};