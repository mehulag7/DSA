class Solution {
public:
int largestRectangleArea(vector<int>& arr) {
          stack<int> st;
        int n=arr.size();
        int ans=0;
        //vector<int> prev(n);
        for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]>=arr[i]) {
            int ele=st.top();
            st.pop();
            int p= st.empty()? -1:st.top();
            int x=arr[ele]*(i-p-1);
            ans=max(ans,x);
           }
           st.push(i);
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int p= st.empty()? -1:st.top();
            int x=arr[ele]*(n-p-1);
            ans=max(ans,x);
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