class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> st;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.back()]<=nums[i]) st.pop_back();
            while(!st.empty() && i-st.front()>=k) st.pop_front();
            st.push_back(i);
            if(i>=k-1){
              ans.push_back(nums[st.front()]);
            }

        }
        return ans;
    }
};