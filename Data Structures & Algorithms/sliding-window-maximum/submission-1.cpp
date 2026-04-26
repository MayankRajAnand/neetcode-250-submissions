class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>dq;
       int i=0;
       int j=0;

        vector<int>ans;
        while(j<nums.size()){
            while(!dq.empty() and nums[dq.back()]<nums[j])dq.pop_back();
            
            dq.push_back(j);

            if(j-i+1==k){
                ans.push_back(nums[dq.front()]);
                if(i==dq.front())dq.pop_front();
                i++;
            }
            j++;
        }
        return ans; 
    }
};
