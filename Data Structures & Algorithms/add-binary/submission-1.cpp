class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;

        int carry=0;
        int sum=0;
        string ans;
        while(i>=0 or j>=0){
            sum+=carry;

            if(i>=0){
                sum+=a[i]-'0';
                i--;
            };
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            ans+=to_string(sum%2);
            carry=sum/2;
            sum=0;
            
        }

        while(carry){
            ans+=to_string(carry%2);
            carry/=2;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};