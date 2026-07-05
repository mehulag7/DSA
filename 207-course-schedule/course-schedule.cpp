class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> visited(n,0);
        vector<int> in(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++){
          adj[p[i][1]].push_back(p[i][0]);
          in[p[i][0]]++;
        }
        int c=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int i=q.front();
            q.pop();
            c++;
            for(auto j:adj[i]){
                in[j]--;
                if(in[j]==0) q.push(j);
            }
        }
        if(c==n) return true;
        else return false;
    }
};