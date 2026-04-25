class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it:nums){
            s.insert(it);
        }

        int ans=0;
        for(auto it:nums){
            if(s.find(it-1)!=s.end())continue;
            else{
                int el=it;
                int c=0;
                while(s.find(el)!=s.end()){
                    el++;
                    c++;

                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};
