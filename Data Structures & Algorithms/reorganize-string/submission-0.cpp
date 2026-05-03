class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }

        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }

        string ans;
        while(pq.size()>=2){
            auto x=pq.top();
            pq.pop();

            auto y=pq.top();
            pq.pop();

            ans+=x.second;
            ans+=y.second;

            if(x.first>1){
                pq.push({x.first-1,x.second});
            }

            if(y.first>1){
                pq.push({y.first-1,y.second});
            }
        }

        if(pq.empty())return ans;

        if(pq.top().first>1)return "";
        ans+=pq.top().second;
        return ans;

    }
};