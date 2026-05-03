class Solution {
public:
    string decodeString(string s) {
        string currString="";
        int num=0;
        stack<string>st;
        for(auto it:s){
            if(it=='['){
                st.push(currString);
                st.push(to_string(num));
                currString="";
                num=0;
            }
            else if(it==']'){
                int d=stoi(st.top());
                st.pop();

                string prev=st.top();st.pop();

                string temp;
                for(int k=0;k<d;k++)temp+=currString;

                currString=prev + temp;

            }
            else if(isdigit(it)) num=num*10+(it-'0');
            else currString+=it;
        }
        return currString;
    }
};