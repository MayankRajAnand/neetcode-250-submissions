class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        int dig=0;
       
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                dig=dig*10 + (s[i]-'0');
            }
            else if(s[i]=='['){
                st.push(to_string(dig));
                dig=0;
                st.push("[");
            }
            else if(s[i]==']'){
                string temp="";
                while(st.top()!="["){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop(); //Remove opening bracket
                
                int num=stoi(st.top());
                st.pop();

                string repeated;
                for(int k=0;k<num;k++)repeated.append(temp);
                st.push(repeated);
            }
            else st.push(string(1, s[i]));
        }

        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};