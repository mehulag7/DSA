class Solution {
public:
int largestRectangleArea(vector<int>& arr) {
          stack<int> st;
        int n=arr.size();
        int ans=0;
        long long m=1e9+7;
        vector<int> prev(n);
        for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
           if(st.empty()) prev[i]=-1;
           else prev[i]=st.top();
           st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
           if(st.empty()) nse[i]=n;
           else nse[i]=st.top();
           st.push(i);
        }
        for(int i=0;i<n;i++){
            int p=nse[i]-prev[i]-1;
            ans=max(ans,p*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> v(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') v[i][j]=0;
                else v[i][j]=1;
            }
        }
        int ans=0;
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++)  ans=max(ans,largestRectangleArea(v[i]));
        return ans;
    }
};