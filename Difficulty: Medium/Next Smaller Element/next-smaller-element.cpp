class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        int n=arr.size();
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]) st.pop();
            v[i]=st.empty()? -1:st.top();
            st.push(arr[i]);
        }
        return v;
    }
};