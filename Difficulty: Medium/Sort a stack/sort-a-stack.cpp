class Solution {
  public:
  void insert(stack<int> &st,int a){
      if(st.empty() ||st.top()<=a){
            st.push(a);
        }
        else{
            int p=st.top();
            st.pop();
            insert(st,a);
            st.push(p);
        }
  }
    void sortStack(stack<int> &st) {
        if(!st.empty()){
        // code here
        int a=st.top();
        st.pop();
        sortStack(st);
        insert(st,a);
    }
    }
};
