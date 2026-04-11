class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                int p=abs(asteroids[i]);
                int k=0;
                while(!st.empty() && st.top()>0 && st.top()<p){
                    st.pop();
                }
                if(!st.empty() && st.top()==p) {
                    st.pop();
                    k++;
                }
                if((st.empty() || st.top()<0) && k==0) st.push(asteroids[i]);
            }
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};