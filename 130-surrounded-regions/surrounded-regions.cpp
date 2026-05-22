class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>> v(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(board[0][i]=='O') {
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[n-1][i]=='O') {
                q.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
        for(int i=1;i<n-1;i++){
            if(board[i][0]=='O') {
                q.push({i,0});
                visited[i][0]=1;
            }
            if(board[i][m-1]=='O') {
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        vector<int> r={-1,0,0,1};
        vector<int> s={0,1,-1,0};
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            v[a][b]='O';
            for(int i=0;i<4;i++){
                int x=a+r[i];
                int y=b+s[i];
                if(x>=0 && x<n && y>=0 && y<m && board[x][y]=='O' && visited[x][y]==0){
                    q.push({x,y});
                    visited[x][y]=1;
                }
            }
        }
        board=v;
        return;
    }
};