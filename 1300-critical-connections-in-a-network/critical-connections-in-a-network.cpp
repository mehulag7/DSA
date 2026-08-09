class Solution {
public:
    int timer=0;
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<vector<int>>& ans,vector<int>& low,vector<int>& disc){
        timer++;
        low[node]=timer;
        disc[node]=timer;
        for(auto adjnode:adj[node]){
            if(adjnode!=parent){
                if(disc[adjnode]==0){
                    dfs(adjnode,node,adj,ans,low,disc);
                    low[node]=min(low[node],low[adjnode]);
                }
                else{
                    low[node]=min(low[node],disc[adjnode]);
                }
                if(low[adjnode]>disc[node]){
                    ans.push_back({node,adjnode});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> disc(n,0);
        vector<int> low(n,0);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(disc[i]==0){
                dfs(i,-1,adj,ans,low,disc);
            }
        }
        return ans;
    }
};