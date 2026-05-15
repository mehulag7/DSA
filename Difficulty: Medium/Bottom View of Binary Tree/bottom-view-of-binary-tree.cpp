/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
         map<int,int> mpp;
        queue<pair<Node*,int>> st;
        st.push({root,0});
        while(!st.empty()){
            int sz=st.size();
            //map<int,vector<int>> mpp1;
            for(int i=0;i<sz;i++){
                Node* x=st.front().first;
                int y=st.front().second;
                st.pop();
                if(x->left) st.push({x->left,y-1});
                if(x->right) st.push({x->right,y+1});
             mpp[y]=(x->data);
            }
            }
        vector<int> ans;
        for(auto i:mpp){
            int v=i.second;
          ans.push_back(v);
        }
        return ans;
    }
};