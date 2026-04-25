class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int i=0;
        int j=0;

        int maxChar=0;
        int ans=0;
        while(j<s.size()){
            m[s[j]]++;
            maxChar=max(maxChar,m[s[j]]);

            while(j-i+1-maxChar>k){
                m[s[i]]--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
