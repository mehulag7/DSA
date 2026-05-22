class Solution {
private:
   void dfs(int i,int j,vector<vector<char>>& copy){
    copy[i][j]='0';
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if(nrow>=0 && nrow<copy.size() && ncol>=0 && ncol<copy[0].size() && copy[nrow][ncol]=='1'){
            dfs(nrow,ncol,copy);
        }
    }
   }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        vector<vector<char>> copy=grid;
        for(int i=0;i<copy.size();i++){
            for(int j=0;j<copy[0].size();j++){
                if(copy[i][j]=='1'){
                    cnt++;
                    dfs(i,j,copy);
                }
            }
        }
        return cnt;
    }
};