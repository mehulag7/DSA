class Solution {
public:
    bool dfs(int i,int c,vector<vector<int>>& graph,vector<int>& color){
        color[i]=c;
        for(int j=0;j<graph[i].size();j++){
            if(color[graph[i][j]]==-1) if(dfs(graph[i][j],1-c,graph,color)==false) return false;
            if(color[graph[i][j]]==color[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); 
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1) if(dfs(i,0,graph,color)==false) return false;
        }
        return true;
    }
};