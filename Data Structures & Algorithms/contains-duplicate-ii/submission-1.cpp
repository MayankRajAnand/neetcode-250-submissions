class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(s.find(nums[j])!=s.end())return true;
            s.insert(nums[j]);

            if(j-i>=k){
                s.erase(nums[i]);
                i++;
            }

            j++;
        }
        return false;
    }
};