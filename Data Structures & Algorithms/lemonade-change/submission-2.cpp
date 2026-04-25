class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;

        for(auto it:bills){
            switch(it){
                case 5: 
                    five++;
                    break;
                case 10:
                    if(five<=0)return false;
                    five--;
                    ten++;
                    break;
                case 20:
                    if(ten>0 and five>0){
                        ten--;
                        five--;
                    }
                    else if(five>=3){
                        five-=3;
                    }
                    else return false;
                    break;
            }
        }
        return true;
    }
};