class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto &it:asteroids){
            while(!st.empty() and st.top()>0 and it<0){
                int x=st.top()+it;
                if(x>0){
                    it=0;
                }
                else if(x<0){
                    st.pop();
                }
                else{
                    st.pop();
                    it=0;
                }
            }
            if(it!=0)st.push(it);
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};