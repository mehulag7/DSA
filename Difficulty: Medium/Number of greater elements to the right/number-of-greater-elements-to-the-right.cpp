
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n=arr.size();
        int m=indices.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=indices[i]+1;j<=n-1;j++){
                if(arr[j]>arr[indices[i]]){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};