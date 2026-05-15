/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mpp;
        queue<pair<TreeNode*,int>> st;
        st.push({root,0});
        while(!st.empty()){
            int sz=st.size();
            map<int,vector<int>> mpp1;
            for(int i=0;i<sz;i++){
                TreeNode* x=st.front().first;
                int y=st.front().second;
                st.pop();
                if(x->left) st.push({x->left,y-1});
                if(x->right) st.push({x->right,y+1});
                mpp1[y].push_back(x->val);
            }
            for(auto i:mpp1){
                        vector<int> v=i.second;
            sort(v.begin(),v.end());  
            for(int j=0;j<v.size();j++) mpp[i.first].push_back(v[j]);  
            }
        } 
        vector<vector<int>> ans;
        for(auto i:mpp){
            vector<int> v=i.second;
          ans.push_back(v);
        }
        return ans;
    }
};