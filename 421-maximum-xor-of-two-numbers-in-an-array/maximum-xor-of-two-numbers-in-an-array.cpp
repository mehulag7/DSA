struct Node{
    Node* links[2];
    Node(){
        links[0]=NULL;
        links[1]=NULL;
    }
    bool containsKey(int x){
        return links[x]!=NULL;
    }
    Node* getKey(int x){
        return links[x];
    }
    void put(int x,Node* n){
        links[x]=n;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int x){
        Node* node=root;
        for(int i=31;i>=0;i--){
            if(x&(1<<i)){
               if(node->containsKey(1)){
                node=node->getKey(1);
               }
               else{
                node->put(1,new Node());
                node=node->getKey(1);
               }
            }
            else{
                if(!node->containsKey(0)){
                   node->put(0,new Node());
                }
                node=node->getKey(0);
            }
        }
    }
    int getMax(int num){
        int ans=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit;
            if((1<<i)&num) bit=0;
            else bit=1;
            if(node->containsKey(bit)){
                ans+=(1<<i);
                node=node->getKey(bit);
            }
            else{
                node=node->getKey(1-bit);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tr;
        for(int i=0;i<nums.size();i++) tr.insert(nums[i]);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,tr.getMax(nums[i]));
        }
        return ans;
    }
};