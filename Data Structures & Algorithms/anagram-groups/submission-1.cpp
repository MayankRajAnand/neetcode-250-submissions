class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;

        for(auto word:strs){
            vector<int>v(26,0);

            for(auto it:word){
                v[it-'a']++;
            }

            string key;
            for(int i=0;i<26;i++){
                if(v[i]>0){
                    key += char(i + 'a'); 
                    key += to_string(v[i]);
                    key += '#';
                }
            }
            m[key].push_back(word);
        }   

        vector<vector<string>>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
