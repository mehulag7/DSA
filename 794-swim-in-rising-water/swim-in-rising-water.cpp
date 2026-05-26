class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > q;
        q.push({grid[0][0],{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        int drow[4]={-1,0,0,1};
        int dcol[4]={0,1,-1,0};
        while(!q.empty()){
            int t=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            if(dist[row][col]<t) continue;
            if(row==n-1 && col==m-1) return t;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist[nrow][ncol]>max(dist[row][col],grid[nrow][ncol])){
                    dist[nrow][ncol]=max(dist[row][col],grid[nrow][ncol]);
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};