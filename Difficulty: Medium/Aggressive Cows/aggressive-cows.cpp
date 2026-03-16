class Solution {
public:
    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int ans=0;
        int low = 1;
        int high = stalls[n-1] - stalls[0];

        while(low <= high){

            int mid = (low + high) / 2;

            int cows = 1;
            int last = stalls[0];

            for(int i = 1; i < n; i++){
                if(stalls[i] - last >= mid){
                    cows++;
                    last = stalls[i];
                }
            }

            if(cows >= k)
            {
                ans=max(ans,mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};