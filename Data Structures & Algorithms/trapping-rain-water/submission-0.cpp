class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxLeft(n,0);
        vector<int>maxRight(n,0);

        for(int i=0;i<n;i++){
            if(i==0)maxLeft[i]=height[i];
            else maxLeft[i]=max(maxLeft[i-1],height[i]);
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1)maxRight[i]=height[n-1];
            else maxRight[i]=max(maxRight[i+1],height[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+= min(maxLeft[i],maxRight[i])-height[i];
        }
        return ans;
    }
};
