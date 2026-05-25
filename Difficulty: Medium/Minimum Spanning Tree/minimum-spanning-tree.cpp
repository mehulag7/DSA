class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int ans=0;
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > q;
        q.push({0,{0,-1}});
        vector<int> vis(V,0);
        while(!q.empty()){
            int wt=q.top().first;
            int node=q.top().second.first;
            int parent=q.top().second.second;
            q.pop();
            if(vis[node]) continue;
            else{
                vis[node]=1;
                ans+=wt;
            }
            for(auto i:adj[node]){
                if(!vis[i.first]){
                    q.push({i.second,{i.first,node}});
                }
            }
        }
        return ans;
    }
};