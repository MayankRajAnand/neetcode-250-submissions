class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto it:strs){
            s+= to_string(it.size());
            s+='#';
            s+=it;
        }
        return s;
    }

    vector<string> decode(string s) {
        int j=0;

        vector<string>ans;
        
        while(j<s.size()){
            int n=0;
            while(s[j]!='#'){
                n=n*10 + (s[j]-'0');
                j++;
            }
            j++;
            ans.push_back(s.substr(j,n));
            j+=n;
        }

        return ans;
    }
};
