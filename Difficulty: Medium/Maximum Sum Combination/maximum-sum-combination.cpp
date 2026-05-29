class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<pair<int,int>> pq;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=b.size();
        for(int i=0;i<a.size();i++){
            pq.push({a[i]+b[n-1],n-1});
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            int index=pq.top().second;
            if(ans.size()==k) break;
            pq.pop();
            if(index-1>=0){
                pq.push({ans.back()-b[index]+b[index-1],index-1});
            }
        }
    
        return ans;
    }
};