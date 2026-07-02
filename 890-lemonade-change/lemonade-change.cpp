class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0,count10=0,count20=0;
        for(auto bill:bills){
            if(bill==5){
                count5++;
                continue;
            }
            else if(bill==10){
                if(count5){
                    count5--;
                    count10++;
                }
                else return false;
            }
            else{
                if(count5 && count10){
                    count5--;
                    count10--;
                    count20++;
                }
                else if(count5>=3) {
                    count5-=3;
                    count20++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};