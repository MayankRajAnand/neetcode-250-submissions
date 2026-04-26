class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n){
            int rsb= n&-n;
            c++;
            n-=rsb;
        }
        return c;
    }
};
