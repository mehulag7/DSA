class Disjoint{
public:

    vector<int> sz,parent;

    Disjoint(int n){

        sz.resize(n+1,1);

        parent.resize(n+1);

        for(int i=0;i<=n;i++){

            parent[i]=i;
        }
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

            parent[a]=b;

            sz[b]+=sz[a];
        }
        else{

            parent[b]=a;

            sz[a]+=sz[b];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n*n);
        int drow[4]={-1,0,0,1};
        int dcol[4]={0,1,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                for(int k=0;k<4;k++){
                    int row=i+drow[k];
                    int col=j+dcol[k];
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]) ds.unionby(row*n+col,i*n+j);
                }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) ans=max(ans,ds.sz[ds.findUp(i*n+j)]);
                else{
                    int cnt=1;
                    set<int> s;
                    for(int k=0;k<4;k++){
                    int row=i+drow[k];
                    int col=j+dcol[k];
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]) {
                         s.insert(ds.findUp(row*n+col));
                    }
                    }
                    for(auto i:s){
                        cnt+=ds.sz[i];
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};