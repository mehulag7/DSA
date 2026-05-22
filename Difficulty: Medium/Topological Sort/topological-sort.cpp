class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> in(V,0);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            in[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i); 
        }
        vector<int> vis(V,0);
        vector<int> ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            vis[a]=1;
            ans.push_back(a);
            for(auto e:adj[a]){
                in[e]--;
                if(in[e]==0 && vis[e]==0){
                    q.push(e);
                }
            }
        }
        return ans;
    }
};