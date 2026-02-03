class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;          // ✅ uniqueness enforced
        map<long long,long long> mpp;
        vector<int> pos, neg;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
            if(nums[i] > 0) pos.push_back(nums[i]);
            if(nums[i] < 0) neg.push_back(nums[i]);
        }

        // (0,0,0)
        if(mpp[0] > 2){
            st.insert({0,0,0});
        }

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end(), greater<int>());

        // (0, x, -x)
        if(mpp[0] > 0){
            for(int i = 0; i < pos.size(); i++){
                if(i > 0 && pos[i] == pos[i-1]) continue;
                if(mpp[-pos[i]] > 0){
                    vector<int> t = {0, pos[i], -pos[i]};
                    sort(t.begin(), t.end());
                    st.insert(t);
                }
            }
        }

        // (pos, neg, third)
        for(int i = 0; i < pos.size(); i++){
            for(int j = 0; j < neg.size(); j++){

                int third = -1 * (pos[i] + neg[j]);

                if(pos[i] == (-neg[j]) * 2){
                    if(mpp[neg[j]] > 1){
                        vector<int> t = {pos[i], neg[j], third};
                        sort(t.begin(), t.end());
                        st.insert(t);
                    }
                    break;
                }
                else if(pos[i] <= (-neg[j]) * 2) break;
                else if(mpp[third] > 0){
                    vector<int> t = {pos[i], neg[j], third};
                    sort(t.begin(), t.end());
                    st.insert(t);
                }
            }
        }

        // (neg, pos, third)
        for(int i = 0; i < neg.size(); i++){
            for(int j = 0; j < pos.size(); j++){

                int third = -1 * (pos[j] + neg[i]);

                if(-neg[i] == pos[j] * 2){
                    if(mpp[pos[j]] > 1){
                        vector<int> t = {pos[j], pos[j], neg[i]};
                        sort(t.begin(), t.end());
                        st.insert(t);
                    }
                    break;
                }
                else if(-neg[i] <= pos[j] * 2) break;
                else if(mpp[third] > 0){
                    vector<int> t = {pos[j], third, neg[i]};
                    sort(t.begin(), t.end());
                    st.insert(t);
                }
            }
        }

        // set → vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
