/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root,TreeNode* x,TreeNode* p,vector<TreeNode*>& a){
        if(x==NULL) return false;
       if(x==p){
           a.push_back(x);
           return true;
       }
       else{
           if(path(root,x->left,p,a)) {
            a.push_back(x);
            return true;
           }
           else if(path(root,x->right,p,a)){
            a.push_back(x);
            return true;
           }
           else return false;
       }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
        path(root,root,p,a);
        path(root,root,q,b);
        map<TreeNode*,int> mpp;
        for(int i=0;i<a.size();i++){
            mpp[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(mpp[b[i]]==1) return b[i];
        }
        return root;
    }
};