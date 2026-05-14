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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int count=0;
        if(root==NULL) return ans;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int p=st.size();
            vector<int> k;
            for(int i=0;i<p;i++){
                TreeNode* x=st.front();
                st.pop();
                k.push_back(x->val);
                if(x->left) st.push(x->left);
                if(x->right) st.push(x->right);
            }
            if(count%2){
                reverse(k.begin(),k.end());
            }
            count++;
            ans.push_back(k);
        }
        return ans;
    }
};