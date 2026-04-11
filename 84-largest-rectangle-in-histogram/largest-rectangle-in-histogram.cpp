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
};