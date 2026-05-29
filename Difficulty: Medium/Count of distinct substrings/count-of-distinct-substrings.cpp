class Node{
public:
    Node* links[26];

    Node(){
        for(int i=0;i<26;i++) links[i]=NULL;
    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
};

class Solution {
public:
    int countSubs(string &s) {

        Node* root = new Node();

        int cnt = 0;

        for(int i=0;i<s.size();i++){

            Node* node = root;

            for(int j=i;j<s.size();j++){

                if(!node->containsKey(s[j])){

                    node->put(s[j],new Node());

                    cnt++;
                }

                node = node->get(s[j]);
            }
        }

        return cnt ;   // +1 for empty substring
    }
};