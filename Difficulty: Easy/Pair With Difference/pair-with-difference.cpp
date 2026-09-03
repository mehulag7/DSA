
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // code here
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(x==0){
                if(mpp[arr[i]]>=2) return true;
            }
            else if(mpp[arr[i]+x] || mpp[arr[i]-x]) return true;
        }
        return false;
    }
};
