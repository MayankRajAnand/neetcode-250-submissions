class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto it:tokens){
            if (it != "+" && it != "-" && it != "*" && it != "/")st.push(stoi(it));
            else{
                int second=st.top();st.pop();
                int first=st.top();st.pop();

                if(it=="+")st.push(first+second);
                else if(it=="-")st.push(first-second);
                else if(it=="*")st.push(first*second);
                else st.push(first/second);
            }
        }
        return st.top();
    }
};
