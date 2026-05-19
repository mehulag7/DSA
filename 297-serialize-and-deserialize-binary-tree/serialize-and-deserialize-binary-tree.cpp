/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string a="";

        if(root==NULL) return a;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            TreeNode* x=q.front();
            q.pop();

            if(x){

                a += to_string(x->val) + ',';

                q.push(x->left);
                q.push(x->right);
            }
            else{
                a += "#,";
            }
        }

        return a;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size()==0) return NULL;

        string p="";
        int i=0;

        while(data[i]!=','){
            p+=data[i];
            i++;
        }

        i++;

        TreeNode* root=new TreeNode(stoi(p));

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            TreeNode* x=q.front();
            q.pop();

            string e="",f="";

            while(i<data.size() && data[i]!=','){
                e+=data[i];
                i++;
            }

            i++;

            while(i<data.size() && data[i]!=','){
                f+=data[i];
                i++;
            }

            i++;

            if(e!="#"){

                x->left=new TreeNode(stoi(e));

                q.push(x->left);
            }

            if(f!="#"){

                x->right=new TreeNode(stoi(f));

                q.push(x->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));