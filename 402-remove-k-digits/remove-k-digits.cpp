class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n=nums.length();
        int p=k;
        stack<char> st;
        for(int i=0;i<nums.length();i++){
            while(!st.empty() && p>0 && (st.top()-'0')>(nums[i]-'0')){
                st.pop();
                p--;
            }
            st.push(nums[i]);
        }
        while(!st.empty() && p>0) {
            st.pop();
            p--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int s=0;
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='0') s++;
            else break;
        }
        cout<<s;
       string ans1=ans.substr(s);
       if(ans1.empty()) ans1="0";
        return ans1;
    }
};