class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {

        unordered_map<int,int> mpp;
        long long sum = 0;
        long long ans = 0;

        mpp[0] = 1;   // ✅ base case

        for(int i = 0; i < arr.size(); i++){
            sum ^= arr[i];

            ans += mpp[sum ^ k];  // ✅ core logic

            mpp[sum]++;           // store prefix XOR
        }
        return ans;
    }
};
