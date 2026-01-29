class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int ans=1,c=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]+1){
                c++;
            }
            else if(arr[i]==arr[i-1]) continue;
            else {
                ans=max(ans,c);
                c=1;
            }
        }
        ans=max(ans,c);
        return ans;
    }
};