class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;

        for(auto it:arr){
            int dist=abs(it-x);
            pq.push({dist,it});

            if(pq.size()>k)pq.pop();
        }

        vector<int>ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            ans.push_back(it.second);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};