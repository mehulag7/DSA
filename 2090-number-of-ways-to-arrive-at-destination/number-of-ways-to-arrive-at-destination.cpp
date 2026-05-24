class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Converted adjacency list to use long long for weights
        vector<vector<pair<long long, long long>>> adj(n);
        for(long long i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        long long M = 1e9 + 7;
        
        // Converted priority queue types to handle long long distances
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>
                       > q;
        
        q.push({0, 0});
        
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        
        vector<long long> ways(n, 0);
        ways[0] = 1;
        
        while(!q.empty()){
            long long val = q.top().first;
            long long node = q.top().second;
            q.pop();
            
            // Critical optimization: skip stale, longer paths in the queue
            if (val > dist[node]) continue;
            
            for(auto i : adj[node]){
                long long adjNode = i.first;
                long long edgeWeight = i.second;
                
                if(dist[adjNode] > val + edgeWeight){
                    dist[adjNode] = val + edgeWeight;
                    q.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist[adjNode] == val + edgeWeight) {
                     ways[adjNode] = (ways[adjNode] % M + ways[node] % M) % M;
                }
            }
        }
        
        // The return type required by the function signature is int
        return ways[n - 1] % M;
    }
};