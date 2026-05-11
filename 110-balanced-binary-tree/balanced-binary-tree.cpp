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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode* s=root;
        stack<TreeNode*> st;
        st.push(root);
        bool ans=true;
        map<TreeNode*,int> mpp;
        while(!st.empty()){
            TreeNode* x=st.top();
            if(x->left==NULL && x->right==NULL) {
                mpp[x]=1;
                st.pop();
            }
            else if(x->left==NULL && x->right!=NULL){
                if(mpp.count(x->right)){
                    if(mpp[x->right]>1) ans=false;
                 mpp[x]=1+mpp[x->right];
                 st.pop();
                }
                else{
                  st.push(x->right);
                }
            }
            else if(x->left!=NULL && x->right==NULL){
                if(mpp.count(x->left)){
                    if(mpp[x->left]>1) ans=false;
                 mpp[x]=1+mpp[x->left];
                 st.pop();
                }
                else{
                  st.push(x->left);
                }
            }
            else{
               if(mpp.count(x->right) && mpp.count(x->left)){
                if(abs(mpp[x->right]-mpp[x->left])>1) ans=false;
                mpp[x]=1+max(mpp[x->right],mpp[x->left]);
                st.pop();
               }
               else{
                st.push(x->right);
                st.push(x->left);
               }
            }
        }
        return ans;
    }
};