class Solution {
public:

    string findOrder(vector<string> &words) {

        int n = words.size();

        if(n == 1){
            string ans="";
             vector<int> present(26,0);

        for(auto &x : words){
            for(auto &c : x){
                present[c-'a'] = 1;
            }
        }
        for(int i=0;i<26;i++) if(present[i]) ans+=('a'+i);
        return ans;
        }

        vector<int> adj[26];

        vector<int> present(26,0);

        for(auto &x : words){
            for(auto &c : x){
                present[c-'a'] = 1;
            }
        }

        for(int i=1;i<n;i++){

            int mn = min(words[i].length(),words[i-1].length());
            int o=-1;

            for(int j=0;j<mn;j++){

                if(words[i-1][j] != words[i][j]){

                    adj[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                    o=1;

                    break;
                }
            }
            if(o==-1){
                if(words[i-1].length()>words[i].length()) return "";
            }
        }

        vector<int> in(26,0);

        for(int i=0;i<26;i++){

            for(int j=0;j<adj[i].size();j++){

                in[adj[i][j]]++;
            }
        }

        queue<int> q;

        for(int i=0;i<26;i++){

            if(present[i] && in[i]==0){

                q.push(i);
            }
        }

        string ans="";

        while(!q.empty()){

            int k=q.front();

            q.pop();

            ans += char('a'+k);

            for(auto i:adj[k]){

                in[i]--;

                if(in[i]==0){

                    q.push(i);
                }
            }
        }

        for(int i=0;i<26;i++){

            if(present[i] && in[i]!=0){

                return "";
            }
        }

        return ans;
    }
};