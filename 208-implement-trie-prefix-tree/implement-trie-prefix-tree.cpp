struct Node{
   Node* links[26];
   bool flag;
   bool containskey(char ch){
    if(links[ch-'a']!=NULL) return true;
    else return false;
   }

   void put(char ch,Node* n){
    links[ch-'a']=n;
   }

   Node* getkey(char ch){
    return links[ch-'a'];
   }

   bool isEnd(){
    return flag;
   }

   void markEnd(){
     flag=true;
   }
};
class Trie {
public:
Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getkey(word[i]);
        }
        node->markEnd();
    }
    
    bool search(string word) {
         Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->getkey(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
         Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->getkey(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */