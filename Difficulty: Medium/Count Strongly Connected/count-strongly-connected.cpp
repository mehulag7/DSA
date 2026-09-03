class Solution {
  public:
    void dfs(int i,vector<int> &vis,stack<int>& st,vector<vector<int>>& adj){
        vis[i]=1;
        for(auto node:adj[i]){
            if(!vis[node]) dfs(node,vis,st,adj);
        }
        st.push(i);
    }
    void dfs1(int i,vector<int> &vis,vector<vector<int>>& adj){
        vis[i]=1;
        for(auto node:adj[i]){
            if(!vis[node]) dfs1(node,vis,adj);
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        stack<int> st;
        vector<vector<int>> adj(V),adj1(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj1[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V,0),vis1(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,vis,st,adj);
        }
        int ans=0;
        while(!st.empty()){
            if(!vis1[st.top()]){
                ans++;
                dfs1(st.top(),vis1,adj1);
            }
            st.pop();
        }
        return ans;
    }
};