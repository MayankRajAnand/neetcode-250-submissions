class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0;
        int c2=0;

        int m1=NULL;
        int m2=NULL;

        for(auto it:nums){
            if(it==m1)c1++;
            else if(it==m2)c2++;

            else if(c1==0){
                c1++;
                m1=it;
            }
            else if(c2==0){
                c2++;
                m2=it;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int>ans;
        int f1=0;
        int f2=0;
        //verify
        for(auto it:nums){
            if(it==m1)f1++;
            else if(it==m2)f2++;
        }

        if(f1> floor(nums.size()/3))ans.push_back(m1);
        if(f2> floor(nums.size()/3))ans.push_back(m2);

        return ans;
        

    }
};