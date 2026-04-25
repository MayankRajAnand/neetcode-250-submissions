class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        
        vector<int>v(26,0);

        for(auto it:s){
            v[it-'a']++;
        }

        for(auto it:t){
           if(v[it-'a']<=0)return false;
           v[it-'a']--;
        }

        
        return true;
    }
};
