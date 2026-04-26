class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(auto it:t)m[it]++;
        int req=t.size();

        int i=0;
        int j=0;
        int startLen=0;
        int minLen=INT_MAX;
        while(j<s.size()){
            if(m[s[j]]>0)req--;
            m[s[j]]--;

            while(req==0){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    startLen=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0)req++;
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX)return "";
        return s.substr(startLen,minLen);
    }
};
