class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>nextGreater(n,0);
        
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and temperatures[i]>=temperatures[st.top()])st.pop();

            if(st.empty())nextGreater[i]=0;
            else nextGreater[i]=st.top()-i;
            st.push(i);
        }
        return nextGreater;
    }
};
