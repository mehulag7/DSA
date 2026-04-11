class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
         stack<int> st;
        int n=arr.size();
        long long ans=0;
        long long m=1e9+7;
        vector<int> prev(n);
        for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
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
        while(!st.empty()) st.pop();
        vector<int> prev1(n);
        for(int i=0;i<n;i++){
           while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
           if(st.empty()) prev1[i]=-1;
           else prev1[i]=st.top();
           st.push(i);
        }
        vector<int> nge(n);
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
           if(st.empty()) nge[i]=n;
           else nge[i]=st.top();
           st.push(i);
        }
        for(int i=0;i<n;i++){
            int left=i-prev[i];
            int right=nse[i]-i;
            int left1=i-prev1[i];
            int right1=nge[i]-i;
            int c=left1*right1-left*right;
            ans=(ans+(1LL*c*arr[i]));
        }
        return ans;
    }
};