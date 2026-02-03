class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int> v(arr.size(),-1);
        vector<int> ans={-1,-1};
        for(int i=0;i<arr.size();i++){
            v[arr[i]-1]++;
        }
        for(int i=0;i<arr.size();i++){
            if(v[i]==1) ans[0]=i+1;
            if(v[i]==-1) ans[1]=i+1;
        }
        return ans;
    }
};