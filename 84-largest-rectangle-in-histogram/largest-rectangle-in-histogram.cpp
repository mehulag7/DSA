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
};