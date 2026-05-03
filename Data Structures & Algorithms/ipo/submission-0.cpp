class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<capital.size();i++)v.push_back({profits[i],capital[i]});

        sort(v.begin(),v.end(),comp);
        int n=v.size();

        int i=0;
        priority_queue<int>pq;
        while(k>0){
            while(i<n and v[i].second<=w){
                pq.push(v[i].first);
                i++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
            k--;

        }
        return w;

    }
};