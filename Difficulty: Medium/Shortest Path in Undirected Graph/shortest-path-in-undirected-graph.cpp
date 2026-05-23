class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        vector<int> ans(V,-1);
        ans[src]=0;
        q.push({src,0});
        vis[src]=1;
        while(!q.empty()){
            int p=q.front().first;
            int val=q.front().second;
            q.pop();
            for(auto i:adj[p]){
                if(!vis[i]){
                    vis[i]=1;
                    ans[i]=val+1;
                    q.push({i,val+1});
                }
            }
        }
        return ans;
    }
};
