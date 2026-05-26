class Disjoint{
  public:
      vector<int> sz,parent;
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
            parent[a]=b;
            sz[b]+=sz[a];
           }
           else{
            parent[b]=a;
            sz[a]+=sz[b];
           }
           return;
       }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       // vector<pair<int,int>> adj;
        Disjoint ds(n+1);
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0]) ds.unionby(i,j);
                else if(stones[i][1]==stones[j][1]) ds.unionby(i,j);

            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.findUp(i)==i) ans+=ds.sz[i]-1;
        }
        return ans;
    }
};