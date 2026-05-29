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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie tr;
        vector<int> ans(queries.size());
        priority_queue<pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,
        greater<pair<pair<int,int>,int>>
        > pq;
        for(int i=0;i<queries.size();i++){
           pq.push({{queries[i][1],queries[i][0]},i});
        }
        sort(nums.begin(),nums.end());
        int i=0;
        while(!pq.empty()){
            int a=pq.top().first.first;
            while(i<nums.size() && nums[i]<=a){
                    tr.insert(nums[i]);
                    i++;
            }
           if(i!=0) ans[pq.top().second]=tr.getMax(pq.top().first.second);
           else ans[pq.top().second]=-1;
            pq.pop();
        }
        return ans;
    }
};