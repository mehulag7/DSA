class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int> mpp;
       int s=0,e=0;
       int ans=0;
       for(;e<fruits.size();e++){
          mpp[fruits[e]]++;
          while(mpp.size()>2){
            mpp[fruits[s]]--;
            if(mpp[fruits[s]]==0) mpp.erase(fruits[s]);
            s++;
          }
          ans=max(ans,e-s+1);
       }
       return ans;
    }
};