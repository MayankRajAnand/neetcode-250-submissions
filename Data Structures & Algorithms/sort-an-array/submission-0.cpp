class Solution {
public:
    void qs(int lo, int hi,vector<int>&nums){
        if(lo<hi){
            int pivot=quickSort(lo,hi,nums);
            qs(lo,pivot-1,nums);
            qs(pivot+1,hi,nums);
        }
    }

    int quickSort(int lo,int hi,vector<int>&nums){
        int pivot=nums[lo];
        int i=lo+1;
        int j=hi;

        while(i<=j){
            while(nums[i]<=pivot and i<=hi )i++;
            while(nums[j]>pivot and j>=lo)j--;
            if(i<j)swap(nums[i],nums[j]);
        }
        swap(nums[lo],nums[j]);
        return j;
    }
    vector<int> sortArray(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        qs(lo,hi,nums);
        return nums;
    }
};