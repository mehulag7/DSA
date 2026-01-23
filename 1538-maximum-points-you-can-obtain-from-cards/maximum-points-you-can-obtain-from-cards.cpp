class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        long long total=0,sum=0,tk;
        int p=card.size()-k;
        int i=0,j=0;
        for(;j<p;j++){
           total+=card[j];
           sum+=card[j];
        }
        tk=sum;
        while(j<card.size()){
            total+=card[j];
            sum=sum-card[i]+card[j];
            j++;
            i++;
            tk=min(sum,tk);
        }
        //cout<<tk<<" "<<total<<endl;
        return total-tk;
    }
};