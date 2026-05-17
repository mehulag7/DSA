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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           int a=q.size();
           for(int i=0;i<a;i++){
            TreeNode* x=q.front();
            q.pop();
            if(x->left){
                mpp[x->left]=x;
                q.push(x->left);
            }
            if(x->right){
                mpp[x->right]=x;
                q.push(x->right);
            }
           }
        }
        map<TreeNode*,int> visited;
        vector<int> ans;
        int c=0;
        q.push(target);
        visited[target]=1;
        while(!q.empty()){
            int a=q.size();
            if(c==k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            for(int i=0;i<a;i++){
                TreeNode* x=q.front();
            q.pop();
            if(x->left && visited[x->left]==0){
                q.push(x->left);
                visited[x->left]=1;
            }
            if(x->right && visited[x->right]==0){
                q.push(x->right);
                visited[x->right]=1;
            }
            if(mpp[x] && visited[mpp[x]]==0){
                q.push(mpp[x]);
                visited[mpp[x]]=1;
            }
            }
            c++;
        }
        return ans;
    }
};