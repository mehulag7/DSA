class Solution {
public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        
        double low = 0, high = 0;
        
        for(int i = 0; i < n - 1; i++) {
            high = max(high, (double)(stations[i+1] - stations[i]));
        }

        while(high - low > 1e-6) {
            double mid = (low + high) / 2.0;

            int count = 0;

            for(int i = 0; i < n - 1; i++) {
                double dist = stations[i+1] - stations[i];
                count += (int)ceil(dist / mid) - 1;
            }

            if(count > K) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};