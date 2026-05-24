// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(int j=0;j<edges.size();j++){
                if(dist[edges[j][0]]!=1e8 && dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]]){
                    dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
                }
            }
        }
        for(int j=0;j<edges.size();j++){
                if(dist[edges[j][0]]!=1e8 && dist[edges[j][0]]+edges[j][2]<dist[edges[j][1]]){
                    return {-1};
                    dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
                }
            }
            return dist;
    }
};
