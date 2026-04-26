class Solution {
public:
    bool compare(vector<int>&v1, vector<int>&v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
        }
        
        int i=0;
        int j=0;

        while(j<s2.size()){
            v2[s2[j]-'a']++;

            if(j-i+1==s1.size()){
                if(compare(v1,v2))return true;

                v2[s2[i]-'a']--;
                i++;
            }

            j++;
        }
        return false;

    }
};
