class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        string ans;
        while(!pq.empty()){
            auto [count,currChar]=pq.top(); pq.pop();
            int n=ans.size();

            if(n>=2 and ans[n-1]==currChar and ans[n-2]==currChar){
                if(pq.empty()) break;
                auto [nextCount,nextChar]=pq.top(); pq.pop();

                ans+=nextChar;
                nextCount--;
                if(nextCount>0)pq.push({nextCount,nextChar});
            }
            else {
                ans+=currChar;
                count--;
            }
            if(count>0)pq.push({count,currChar});
        }
        return ans;

    }
};