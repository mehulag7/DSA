// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> ans(V,-1);
        ans[0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int p=q.front().first;
            int val=q.front().second;
            q.pop();
            for(auto i:adj[p]){
                if(ans[i.first]==-1) {
                    ans[i.first]=val+i.second;
                    q.push({i.first,ans[i.first]});
                }
                else{
                      if(ans[i.first]>(val+i.second)){
                          ans[i.first]=val+i.second;
                          q.push({i.first,ans[i.first]});
                      }
                }
                
            }
        }
        return ans;
    }
};
