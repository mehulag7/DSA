/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
         map<Node*,Node*> mpp;
        queue<Node*> q;
        q.push(root);
        Node* t=NULL;
        while(!q.empty()){
           int a=q.size();
           for(int i=0;i<a;i++){
            Node* x=q.front();
            q.pop();
            if(x->data==target) t=x;
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
        map<Node*,bool> visited;
        int ans=0;
        q.push(t);
        visited[t]=true;
        while(!q.empty()){
            int a=q.size();
            for(int i=0;i<a;i++){
                Node* x=q.front();
            q.pop();
            if(x->left && !visited[x->left]){
                q.push(x->left);
                visited[x->left]=true;
            }
            if(x->right && !visited[x->right]){
                q.push(x->right);
                visited[x->right]=true;
            }
            if(mpp[x] && !visited[mpp[x]]){
                q.push(mpp[x]);
                visited[mpp[x]]=true;
            }
            }
            ans++;
        }
        return ans-1;
    }
};