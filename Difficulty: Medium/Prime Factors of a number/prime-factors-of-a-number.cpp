class Solution {
  public:
    vector<int> primeFactors(int n) {
        // code here
        vector<int> ans;
        int p=n;
        for(int i=2;i<=sqrt(n);i++){
            while(n%i==0){
                n=n/i;
                ans.push_back(i);
            }
        }
        if(n!=1) ans.push_back(n);
        return ans;
    }
};
