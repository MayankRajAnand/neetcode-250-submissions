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
        int i=lo;
        int j=hi;

        while(i<j){
            while(i<=hi and nums[i]<=pivot)i++;
            while(j>=lo and nums[j]>pivot)j--;
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