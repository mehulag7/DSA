class Disjoint{
  vector<int> sz,parent;
  public:
       Disjoint(int n){
           sz.resize(n+1,1);
           parent.resize(n+1);
           for(int i=0;i<=n;i++) parent[i]=i;
       }
       int findUp(int u){
           if(parent[u]==u) return u;
           return parent[u]=findUp(parent[u]);
       }
       void unionby(int x,int z){
           int a=findUp(x);
           int b=findUp(z);
           if(a==b) return;
           if(sz[a]<sz[b]){
               sz[b]+=sz[a];
               parent[a]=b;
           }
           else{
               parent[b]=a;
               sz[a]+=sz[b];
           }
       }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int ans=0;
        vector<vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj.push_back({edges[i][2],edges[i][0],edges[i][1]});
        }
        sort(adj.begin(),adj.end());
        Disjoint ds(V+1);
        for(int i=0;i<adj.size();i++){
            if(ds.findUp(adj[i][1])==ds.findUp(adj[i][2])) continue;
            ans+=adj[i][0];
            ds.unionby(adj[i][1],adj[i][2]);
        }
        return ans;
    }
};