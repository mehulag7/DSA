class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int x=0;
        int n=arr.size();
        for(int i=0;i<n;i++) x^=arr[i];
        int p=(x&(x-1))^x;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(arr[i]&p) a^=arr[i];
            else b^=arr[i];
        }
        if(a>b) swap(a,b);
        return {a,b};
    }
};