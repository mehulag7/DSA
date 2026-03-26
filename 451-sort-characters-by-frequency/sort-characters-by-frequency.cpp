class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto i:mpp){
          v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        string p="";
        for(int i=v.size()-1;i>=0;i--){
            for(int j=0;j<v[i].first;j++){
                p+=v[i].second;
            }
        }
        return p;
    }
};