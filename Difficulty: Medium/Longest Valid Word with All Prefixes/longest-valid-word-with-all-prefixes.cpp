struct Node{
   Node* links[26];
   int cp;
   int cw;
   Node(){
    for(int i=0;i<26;i++) links[i]=0;
    cp=0;
    cw=0;
   }
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
            node->cp++;
        }
        node->cw++;
    	}

	    int countWordsEqualTo(string word) {
	        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                 return 0;
            }
            node=node->getkey(word[i]);
        }
        return node->cw;
    	}

	    int countWordsStartingWith(string word) {
	        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                 return 0;
            }
            node=node->getkey(word[i]);
        }
        return node->cp;
    	}

	    void erase(string word) {
	        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containskey(word[i])){
                return;
            }
            node=node->getkey(word[i]);
            node->cp--;
        }
        node->cw--;
	    }
};
class Solution {
public:
    string longestValidWord(vector<string>& words) {

        Trie tr;

        for(int i = 0; i < words.size(); i++) {
            tr.insert(words[i]);
        }

        string ans = "";

        for(int i = 0; i < words.size(); i++) {

            bool flag = true;

            for(int j = 0; j < words[i].length(); j++) {

                string x = words[i].substr(0, j + 1);

                if(tr.countWordsEqualTo(x) == 0) {
                    flag = false;
                    break;
                }
            }

            if(flag) {

                if(words[i].length() > ans.length()) {
                    ans = words[i];
                }
                else if(words[i].length() == ans.length() &&
                        words[i] < ans) {
                    ans = words[i];
                }
            }
        }

        return ans;
    }
};