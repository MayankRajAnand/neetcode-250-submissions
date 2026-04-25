class Solution {
public:
    bool isValid(int i, int j,string s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }

            else{
                return (isValid(i,j-1,s)or isValid(i+1,j,s));
            }
        }
        return true;
    }
};