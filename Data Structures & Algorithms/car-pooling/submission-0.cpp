class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto it:trips){
            pq.push({it[1],it[0]});
            pq.push({it[2],-it[0]});
        }

        int onboard=0;
        while(!pq.empty()){
            onboard+=pq.top().second;
            pq.pop();
            if(onboard>capacity)return false;
        }
        return true;
    }
};