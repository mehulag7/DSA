class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> dist(1000,1e9);
        q.push({0,start});
        while(!q.empty()){
            int steps=q.front().first;
            int point=q.front().second;
            //cout<<point<<endl;
            q.pop();
            if(point==end) return steps;
            for(int i=0;i<arr.size();i++){
                int k=point*arr[i];
                k%=1000;
                if(dist[k]>steps+1) {
                    dist[k]=steps+1;
                    q.push({steps+1,k});
                }
            }
        }
        return -1;
    }
};