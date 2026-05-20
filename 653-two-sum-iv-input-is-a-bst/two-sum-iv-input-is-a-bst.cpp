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
class bst{
public:
    stack<TreeNode*> st;
    bool reverse=true;
    bst(TreeNode* root,bool is){
        reverse=is;
        pushALL(root);
    }
    void pushALL(TreeNode* root){
        if(reverse){
            while(root){
               st.push(root);
               root=root->right;
            }
        }
        else{
            while(root){
               st.push(root);
               root=root->left;
            }
        }
    }
    int next(){
        TreeNode* x=st.top();
        st.pop();
       if(!reverse) pushALL(x->right);
       else pushALL(x->left);
        return x->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       if(!root) false;
       bst l(root,false);
       bst r(root,true);
       int i=l.next();
       int j=r.next();
       while(i<j){
        if((i+j)==k) return true;
        else{
            if(i+j>k){
                j=r.next();
            }
            else i=l.next();
        }
       }
       return false;
    }
};