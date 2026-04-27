class Solution {
public:
    int reverse(int x) {
        int res=0;

        while(x){
            int dig=x%10;
            x/=10;

            if(res>INT_MAX/10 or (res==INT_MAX/10 and dig>7))return 0;
            if(res<INT_MIN/10 or (res==INT_MIN/10 and dig<-8))return 0;

            res=res*10+dig;
        }
        return res;
    }
};
