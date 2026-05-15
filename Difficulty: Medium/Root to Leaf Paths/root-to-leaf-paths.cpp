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
    void path(Node* root,Node* x,vector<vector<int>>& ans,vector<int> v){
        v.push_back(x->data);
        if(x->left==NULL && x->right==NULL){
            ans.push_back(v);
            return;
        }
        else{
            if(x->left) path(root,x->left,ans,v);
            if(x->right) path(root,x->right,ans,v);
        }
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        if(root->left==NULL && root->right==NULL){
            vector<int> v={root->data};
            ans.push_back(v);
            return ans;
        }
        if(root->left!=NULL){
            vector<int> v={root->data};
            path(root,root->left,ans,v);
        }
        if(root->right){
            vector<int> v={root->data};
            path(root,root->right,ans,v);
        }
        return ans;
    }
};