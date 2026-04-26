class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;

        int maxLeft=0;
        int maxRight=0;
        int ans=0;
        while(i<=j){
            if(height[i]<height[j]){
                if(height[i]>maxLeft)maxLeft=height[i];
                else ans+= maxLeft-height[i];
                i++;
            }
            else{
                if(height[j]>maxRight)maxRight=height[j];
                else ans+= maxRight-height[j];
                j--;
            }
        }
        return ans;
    }
};
