class Disjoint{
public:

    vector<int> sz,parent;

    Disjoint(int n){

        sz.resize(n+1,1);

        parent.resize(n+1);

        for(int i=0;i<=n;i++){

            parent[i]=i;
        }
    }

    int findUp(int u){

        if(parent[u]==u) return u;

        return parent[u]=findUp(parent[u]);
    }

    void unionby(int x,int z){

        int a=findUp(x);

        int b=findUp(z);

        if(a==b) return;

        if(sz[a]<sz[b]){

            parent[a]=b;

            sz[b]+=sz[a];
        }
        else{

            parent[b]=a;

            sz[a]+=sz[b];
        }
    }
};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();

        Disjoint ds(n);

        unordered_map<string,int> mailNode;

        for(int i=0;i<n;i++){

            for(int j=1;j<accounts[i].size();j++){

                string mail=accounts[i][j];

                if(mailNode.find(mail)==mailNode.end()){

                    mailNode[mail]=i;
                }
                else{

                    ds.unionby(i,mailNode[mail]);
                }
            }
        }

        vector<string> merged[n];

        for(auto it:mailNode){

            string mail=it.first;

            int node=ds.findUp(it.second);

            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){

            if(merged[i].size()==0) continue;

            sort(merged[i].begin(),merged[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto &x:merged[i]){

                temp.push_back(x);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};