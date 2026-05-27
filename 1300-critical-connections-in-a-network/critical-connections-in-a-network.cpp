class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>&visited,vector<int>& tin,vector<int>& low,vector<vector<int>> &bridges){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(visited[it]==0){
                dfs(it,node,adj,visited,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]) bridges.push_back({it,node});
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        int time=1;
        dfs(0,-1,adj,visited,tin,low,bridges);
        return bridges;
    }
};