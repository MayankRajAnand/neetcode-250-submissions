class Solution {
public:
    void qs(int l,int h,vector<int>& nums){
        if(l<h){
            int pivot=quickSort(l,h,nums);
            qs(l,pivot-1,nums);
            qs(pivot+1,h,nums);
        }
    }

    int quickSort(int lo,int hi,vector<int>& nums){
        int pivot=nums[lo];
        int i=lo;
        int j=hi;

        while(i<j){
            while(i<=hi and nums[i]<=pivot)i++;
            while(j>=lo and nums[j]>pivot)j--;
            if(i<j) swap(nums[i],nums[j]);
        }

        swap(nums[lo],nums[j]);
        return j;
    }

    vector<int> sortArray(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;

        qs(l,h,nums);
        return nums;
    }
};