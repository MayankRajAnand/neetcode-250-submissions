class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorx=0;
        for(auto it:nums){
            xorx^=it;
        }

        for(int i=1;i<=nums.size();i++){
            xorx^=i;
        }
        return xorx;
    }
};
