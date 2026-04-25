class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int el;
        for(auto it:nums){
            if(c==0){
                c++;
                el=it;
            }
            if(it==el)c++;
            else c--;
        }
        return el;
    }
};