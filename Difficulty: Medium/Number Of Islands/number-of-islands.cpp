// User function Template for C++
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        Disjoint ds(k + 1);
        vector<vector<int>> mat(n, vector<int>(m, 0));
        vector<int> ans(k, 0);
        
        vector<int> a = {-1, 0, 0, 1};
        vector<int> b = {0, 1, -1, 0};
        
        int island_count = 0; // Maintain a dynamic running count

        for(int i = 0; i < k; i++){
            int row = operators[i][0];
            int col = operators[i][1];
            
            // Fix 1: If it's a duplicate, the number of islands doesn't change
            if(mat[row][col] != 0){
                ans[i] = island_count; 
                continue;
            }
            
            // Assume it's a new island initially
            mat[row][col] = i + 1;
            island_count++; 
            
            for(int j = 0; j < 4; j++){
                int r = row + a[j];
                int c = col + b[j];
                
                if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c] != 0){
                    int neighbor_id = mat[r][c];
                    int current_id = i + 1;
                    
                    // Fix 2: Only decrement the island count if a successful union happens
                    if(ds.findUp(neighbor_id) != ds.findUp(current_id)) {
                        island_count--; 
                        ds.unionby(neighbor_id, current_id);
                    }
                }
            }
            // Store the dynamic count directly in O(1) time
            ans[i] = island_count;
        }
        return ans;
    }
};