/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void preorder(Node* root,vector<int>& v){
        if(root==NULL) return;
        preorder(root->left,v);
        v.push_back(root->data);
        preorder(root->right,v);
    }
    bool findTarget(Node *root, int target) {
        // code here.
        vector<int> v;
        preorder(root,v);
        unordered_map<int,int> mpp;
        for(int i=0;i<v.size();i++){
            if(mpp[target-v[i]]) return true;
            mpp[v[i]]++;
        }
        return false;
    }
};