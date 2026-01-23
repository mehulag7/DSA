class Solution {
public:
int count(vector<int>&s,int k){
    if(k==0) return 0;
 int i=0,j=0;
        int ans=0;
        unordered_map<int,int> mpp;
        while(j<s.size()){
           mpp[s[j]]++;
           while(mpp.size()>k){
            mpp[s[i]]--;
            if(mpp[s[i]]==0) mpp.erase(s[i]);
            i++;
           }
           if(mpp.size()<=k) {
            ans+=j-i+1;
           }
           j++;
        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& s, int k) {
       return count(s,k)-count(s,k-1);
    }
};