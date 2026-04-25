class Solution {
public:
    void merge(int lo,int mid,int hi,vector<int>&nums){
        vector<int>temp;

        int i=lo;
        int j=mid+1;
        while(i<=mid and j<=hi){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=hi){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
    }
    void mergeSort(int lo,int hi,vector<int>&nums){
        if(lo<hi){
            int mid=lo+(hi-lo)/2;
            mergeSort(lo,mid,nums);
            mergeSort(mid+1,hi,nums);

            merge(lo,mid,hi,nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;

        mergeSort(lo,hi,nums);
        return nums;
    }
};