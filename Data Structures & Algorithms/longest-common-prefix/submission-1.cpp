class Solution {
public:
    string lcp(string a,string b){
        string ans;
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]==b[i])ans+=a[i];
            else return ans;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            ans=lcp(ans,strs[i]);
        }
        return ans;
    }
};