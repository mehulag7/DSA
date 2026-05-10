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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> st;
        st.push(root);
        int ans=0;
        while(!st.empty()){
            int p=st.size();
            for(int i=0;i<p;i++){
                TreeNode* a=st.front();
                if(a->left!=NULL) st.push(a->left);
                if(a->right!=NULL) st.push(a->right);
                st.pop();
            }
            ans++;
        }
        return ans;
    }
};