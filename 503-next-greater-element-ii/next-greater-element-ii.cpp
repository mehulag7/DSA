class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
                int n=nums2.size();
        vector<int> ans(n,1e9);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && st.top() <= nums2[i]) st.pop();

            if (!st.empty()) ans[i]=st.top();
            st.push(nums2[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(ans[i]==1e9){
                while(!st.empty() && st.top()<=nums2[i]) st.pop();
                if(st.empty()) ans[i]=-1;
                else{
                    ans[i]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        return ans;
    }
};