class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
         int n=arr.size();
         sort(arr.begin(),arr.end());
       vector<long long> ans(n,1),h(n,-1);
       for(int i=0;i<n;i++) h[i]=i;
       for(int i=1;i<n;i++){

        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0){
                //ans[i]=max(1+ans[j],ans[i]);
                if(1+ans[j]>ans[i]){
                    ans[i]=1+ans[j];
                    h[i]=j;
                }
            }
        }
       }
       vector<int> f;
       int p=0,ind=-1;
       for(int i=0;i<n;i++){
           if(p<ans[i]){
               p=ans[i];
               ind=i;
           }
       }
       f.push_back(arr[ind]);
       while(ind!=h[ind]){
           f.push_back(arr[h[ind]]);
           ind=h[ind];
       }
       reverse(f.begin(),f.end());
       return f;
    }
};