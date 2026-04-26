class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' or it=='{' or it=='[')st.push(it);
            else if(st.empty() or (it==')' and st.top()!='(') or (it==']' and st.top()!='[') or (it=='}' and st.top()!='{'))return false;
            else st.pop();
        }
        return st.empty();

    }
};
