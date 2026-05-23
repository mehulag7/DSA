class Solution {
public:
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);

        for(int i = 0; i < edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        vector<int> dist(V, 1e9);

        dist[src] = 0;

        q.push({0, src});

        while(!q.empty()) {

            int d = q.top().first;
            int node = q.top().second;

            q.pop();

            if(d > dist[node]) continue;

            for(auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if(d + wt < dist[adjNode]) {

                    dist[adjNode] = d + wt;

                    q.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};