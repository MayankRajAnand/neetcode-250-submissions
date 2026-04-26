class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isOneMissing=true;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)isOneMissing=false;
            else if(nums[i]<=0 or nums[i]>n) nums[i]=1;
        }

        if(isOneMissing)return 1;

        for(int i=0;i<nums.size();i++){
            int ind= abs(nums[i])-1;
            if(nums[ind]>0) nums[ind]*=-1;
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};